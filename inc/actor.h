#ifndef ACTOR
#define ACTOR

#include <cmath>
#include "raylib.h"
#include "raymath.h"

#include "globals.h"

#define SPEED 115.f

#define FRAME_SPEED 8
#define FRAMES 4
#define LAYERS 4

class Actor
{
public:
  bool isMoving;
  int currentCell;
  Vector2 position;

  Actor(Texture2D text, int startCell)
  {
    isMoving = false;
    currentCell = startCell;

    texture = text;

    position = {(startCell % MAP_WIDTH) * CELL_SIZE, (startCell / MAP_WIDTH) * CELL_SIZE};
    frameRec = {0.0f, 0.0f, (float)texture.width / FRAMES, (float)texture.height / LAYERS};
    currentFrame = 0;
    framesCounter = 0;
    framesSpeed = FRAME_SPEED;
  }
  void update();
  void move(Command *command);
  void draw();

private:
  Texture2D texture;
  unsigned int nextFrameOffset;

  Rectangle frameRec;
  int currentLayer;
  int currentFrame;
  int framesCounter;
  int framesSpeed;

  void animate();
};

void Actor::update()
{
  Actor::animate();
}

void Actor::move(Command *command)
{
  // update position
  Vector2 direction = (Vector2){0.f, 0.f};
  switch (*command)
  {
  case Command::N:
    direction += (Vector2){0.f, -1.f};
    currentLayer = 0;
    break;
  case Command::NE:
    direction += (Vector2){DIAGONAL, -DIAGONAL};
    currentLayer = 3;
    break;
  case Command::E:
    direction += (Vector2){1.f, 0.f};
    currentLayer = 3;
    break;
  case Command::SE:
    direction += (Vector2){DIAGONAL, DIAGONAL};
    currentLayer = 3;
    break;
  case Command::S:
    direction += (Vector2){0.f, 1.f};
    currentLayer = 1;
    break;
  case Command::SW:
    direction += (Vector2){-DIAGONAL, DIAGONAL};
    currentLayer = 2;
    break;
  case Command::W:
    direction += (Vector2){-1.f, 0.f};
    currentLayer = 2;
    break;
  case Command::NW:
    direction += (Vector2){-DIAGONAL, -DIAGONAL};
    currentLayer = 2;
    break;
  default:
    return;
  }

  position += Vector2Scale(direction, SPEED * GetFrameTime());

  // update current cell
  Vector2 center = {(position.x + HALF_CELL), (position.y + HALF_CELL)};
  currentCell = (int)floor(center.x / CELL_SIZE) + (int)floor(center.y / CELL_SIZE) * MAP_WIDTH;
}

void Actor::draw()
{
  DrawTextureRec(texture, frameRec, position, WHITE);

  DrawText(TextFormat("pos x: %f\tpos y: %f\tcurrent cell: %i", position.x, position.y, currentCell), 20, 20, 40, BLACK);
}

void Actor::animate()
{
  framesCounter++;
  if (framesCounter >= (FRAME_RATE / framesSpeed))
  {
    currentFrame++;
    framesCounter = 0;
    if (currentFrame >= FRAMES)
    {
      currentFrame = 0;
    }

    frameRec.x = (float)currentFrame * (float)texture.width / FRAMES;
    // frameRec.y = (float)currentLayer * (float)texture.height / LAYERS;
  }
}

#endif
