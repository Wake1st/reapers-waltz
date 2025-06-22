#ifndef TRAP
#define TRAP

#include "raylib.h"
#include "raymath.h"

#include "globals.h"

#define CRUSH_OPENED 400.f
#define CRUSH_CLOSED 0.f
#define CRUSH_SPEED 1200.f

#define SPIKE_TIME 0.1f
#define SPIKE_SCALE 0.018f

class Trap
{
public:
  int cell;

  Trap(Texture2D openTexture, Texture2D closTexture, Sound sfx, int cellIndex)
  {
    openedTexture = openTexture;
    closedTexture = closTexture;
    sound = sfx;
    cell = cellIndex;
    position = PositionOfCell(cellIndex);
  }
  virtual void activate(bool value);
  virtual void update();
  virtual void draw();

protected:
  Texture2D openedTexture;
  Texture2D closedTexture;
  Sound sound;
  Vector2 position;

  bool isActive;
  bool isOpen;
};

class CrushTrap : public Trap
{
public:
  CrushTrap(Texture2D openTexture, Texture2D closTexture, Sound sfx, int cellIndex) : Trap(openTexture, closTexture, sfx, cellIndex)
  {
    offset = {CRUSH_OPENED, 0.f};
  }
  void activate(bool value) override;
  void update() override;
  void draw() override;

private:
  Vector2 offset;
};

void CrushTrap::activate(bool value)
{
  isActive = value;
}

void CrushTrap::update()
{
  if (isActive && isOpen)
  {
    // animate
    offset.y -= CRUSH_SPEED * GetFrameTime();
    if (offset.y < 32.f)
    {
      isOpen = false;
      offset.y = 32.f;

      // play sounds
      PlaySound(sound);
    }
  }
}

void CrushTrap::draw()
{
  // trigger area
  DrawRectangle(position.x, position.y, CELL_SIZE, CELL_SIZE, RED);

  if (isActive)
  {
    if (isOpen)
      DrawTextureEx(openedTexture, Vector2Subtract(position, offset), 0.f, 1.f, WHITE);
    else
      DrawTextureEx(closedTexture, Vector2Subtract(position, offset), 0.f, 1.f, WHITE);
  }
}

class SpikeTrap : public Trap
{
public:
  SpikeTrap(Texture2D openTexture, Texture2D closTexture, Sound sfx, int cellIndex) : Trap(openTexture, closTexture, sfx, cellIndex)
  {
    timer = SPIKE_TIME;
  }
  void activate(bool value) override;
  void update() override;
  void draw() override;

private:
  float timer;
};

void SpikeTrap::activate(bool value)
{
  isActive = value;
}

void SpikeTrap::update()
{
  if (isActive && isOpen)
  {
    // animate
    timer -= GetFrameTime();
    if (timer < 0.f)
    {
      isOpen = false;

      // play sounds
      PlaySound(sound);
    }
  }
}

void SpikeTrap::draw()
{
  // trigger area
  DrawRectangle(position.x, position.y, CELL_SIZE, CELL_SIZE, RED);

  if (isActive)
  {
    if (isOpen)
      DrawTextureEx(openedTexture, Vector2Subtract(position, offset), 0.f, SPIKE_SCALE, WHITE);
    else
      DrawTextureEx(closedTexture, Vector2Subtract(position, offset), 0.f, SPIKE_SCALE, WHITE);
  }
}

#endif
