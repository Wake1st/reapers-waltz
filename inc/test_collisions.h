#ifndef TEST_COLLISIONS
#define TEST_COLLISIONS

#include "map.h"
#include "actor.h"
#include "collision.h"

typedef struct TestCollisionsResources
{
  Texture2D playerTexture;
  MapResources mapRes;
} TestCollisionsResources;

class TestCollisions
{
public:
  TestCollisions(TestCollisionsResources res)
  {
    input = new InputHandler();
    actor = new Actor(res.playerTexture, OUTER_BUFFER + 2 + (OUTER_BUFFER + 1) * MAP_WIDTH);
    map = new Map(res.mapRes);
  }
  void update();
  void draw();

private:
  InputHandler *input;
  Actor *actor;
  Map *map;
};

void TestCollisions::update()
{
  Command command = input->handleInput();
  if (command)
  {
    // check for collisions
    if (!Collision::check(&command, actor->position, map->getNeighbors(actor->currentCell)))
    {
      actor->move(&command);
    }
  }

  actor->update();
}

void TestCollisions::draw()
{
  map->draw();
  actor->draw();

  std::vector<Tile *> tiles = map->getNeighbors(actor->currentCell);
  for (int i = 0; i < 8; i++)
  {
    DrawText(TextFormat("tile pos x: %f\ttile pos y: %f\tcell: %i", tiles[i]->position.x, tiles[i]->position.x, i), 20, 100 + i * 40, 40, BLACK);
  }
}

#endif
