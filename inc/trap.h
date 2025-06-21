#ifndef TRAP
#define TRAP

#include "raylib.h"

#include "globals.h"

class Trap
{
public:
  int cell;

  Trap(Texture2D text, int cellIndex)
  {
    texture = text;
    cell = cellIndex;
    position = PositionOfCell(cellIndex);
  }
  void activate(bool value);
  void update();
  void draw();

private:
  Texture2D texture;
  Vector2 position;

  bool isActive;
};

void Trap::activate(bool value)
{
  isActive = value;
}

void Trap::update()
{
  if (isActive)
  {
    // animate?
    // play sounds?
  }
}

void Trap::draw()
{
  // trigger area
  DrawRectangle(position.x, position.y, CELL_SIZE, CELL_SIZE, RED);

  if (isActive)
  {
    DrawRectangle(position.x, position.y, CELL_SIZE, CELL_SIZE, PINK);
    // DrawTexture(texture, position.x, position.y, WHITE);
  }
}

#endif
