#ifndef GLOBALS
#define GLOBALS

#define FRAME_RATE 60

#define LEVEL_COUNT 1

#define MAP_WIDTH 180
#define MAP_HEIGHT 80
#define MAP_SIZE (MAP_WIDTH * MAP_HEIGHT)

#define CELL_SIZE 32.f
#define OUTER_BUFFER 4.f

#define DIAGONAL 0.7071

typedef enum Command
{
  NONE,
  N,
  NE,
  E,
  SE,
  S,
  SW,
  W,
  NW,
  ACTION,
} Command;

#endif
