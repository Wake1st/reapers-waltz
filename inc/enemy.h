#ifndef ENEMY
#define ENEMY

#include <vector>
#include "raylib.h"
#include "raymath.h"

#include "globals.h"
#include "actor.h"

#define IDLE_TIME 2.5

#define PURSUE_DISTANCE 300.f
#define CAUGHT_DISTANCE 40.f

typedef enum EnemyState
{
  IDLE,
  PATROL,
  PURSUIT,
} EnemyState;

class Enemy
{
public:
  Enemy(Texture2D texture, int startCell, std::vector<int> points)
  {
    patrolPoints = points;
    actor = new Actor(texture, startCell);

    state = EnemyState::IDLE;
    idleTimer = IDLE_TIME;
  }
  void checkPursuit(Actor *check);
  bool checkCaught();
  void update();
  void draw();

private:
  EnemyState state;
  Actor *actor;

  float idleTimer;
  std::vector<int> patrolPoints;
  int pointIndex = 0;

  int targetCell;
  Vector2 target;

  Command getCommand();
};

void Enemy::checkPursuit(Actor *check)
{
  if (Vector2Distance(actor->position, check->position) < PURSUE_DISTANCE)
  {
    targetCell = check->currentCell;
    target = PositionOfCell(targetCell);
    state = EnemyState::PURSUIT;
  }
  else
  {
    state = EnemyState::IDLE;
  }
}

bool Enemy::checkCaught()
{
  if (Vector2Distance(actor->position, target) < CAUGHT_DISTANCE)
  {
    EnemyState::IDLE;
    return true;
  }

  return false;
}

void Enemy::update()
{
  switch (state)
  {
  case EnemyState::IDLE:
  {
    // wait
    idleTimer -= GetFrameTime();
    if (idleTimer <= 0.f)
    {
      // reset the timer
      idleTimer = IDLE_TIME;

      // set new target
      targetCell = patrolPoints[pointIndex];
      pointIndex = (pointIndex + 1) % patrolPoints.size();
      target = PositionOfCell(targetCell);

      // update state
      state = EnemyState::PATROL;
    }

    break;
  }
  case EnemyState::PATROL:
  {
    // move and check destination
    Command command = getCommand();
    if (command)
    {
      actor->move(&command);
    }

    if (actor->currentCell == targetCell)
    {
      state = EnemyState::IDLE;
    }

    break;
  }
  case EnemyState::PURSUIT:
  {
    // move to player
    Command command = getCommand();
    if (command)
    {
      actor->move(&command);
    }
    break;
  }
  }

  // ensure actor is animating
  actor->update();
}

void Enemy::draw()
{
  actor->draw();

  // DrawText(TextFormat("state: %i", state), 20, 100, 20, WHITE);
  // DrawText(TextFormat("target x: %f\ttarget y: %f", target.x, target.y), 20, 140, 20, WHITE);
  // DrawText(TextFormat("actor: %i\ttarget: %i", actor->currentCell, targetCell), 20, 180, 20, WHITE);
}

Command Enemy::getCommand()
{
  int vCells = (targetCell / MAP_WIDTH) - (actor->currentCell / MAP_WIDTH);
  int hCells = (targetCell % MAP_WIDTH) - (actor->currentCell % MAP_WIDTH);

  // printf(TextFormat("\n V: %i\t H: %i", vCells, hCells));

  if (vCells > 0)
  {
    // target is south
    if (hCells > 0)
    {
      return Command::SE;
    }
    else if (hCells < 0)
    {
      return Command::SW;
    }
    else
    {
      return Command::S;
    }
  }
  else if (vCells < 0)
  {
    // target is north
    if (hCells > 0)
    {
      return Command::NE;
    }
    else if (hCells < 0)
    {
      return Command::NW;
    }
    else
    {
      return Command::N;
    }
  }
  else
  {
    // target vertically the same
    if (hCells > 0)
    {
      return Command::E;
    }
    else if (hCells < 0)
    {
      return Command::W;
    }
    else
    {
      return Command::NONE;
    }
  }
}

#endif
