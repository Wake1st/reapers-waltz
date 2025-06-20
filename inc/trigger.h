#ifndef TRIGGER
#define TRIGGER

#include "raylib.h"

#include "globals.h"

class Trigger
{
public:
  bool active = false;

  Trigger(int cellIndex)
  {
    cell = cellIndex;
    position = {(cellIndex % MAP_WIDTH) * CELL_SIZE, (cellIndex / MAP_WIDTH) * CELL_SIZE};
  }
  void activate();
  void draw();

private:
  int cell;
  Vector2 position;
};

void Trigger::activate()
{
  active = true;
}

void Trigger::draw()
{
  DrawRectangle(position.x, position.y, CELL_SIZE, CELL_SIZE, RED);
}

#endif
