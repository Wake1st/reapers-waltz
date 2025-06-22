#ifndef FLOORPLAN
#define FLOORPLAN

#include "raylib.h"

#include "globals.h"

#define ROOM_COUNT 24
#define ROOMS_PER_LEVEL 12

typedef struct Floorplan
{
  Rectangle *rooms[ROOMS_PER_LEVEL];
} Floorplan;

typedef struct Floorplans
{
  static Floorplan *plans[LEVEL_COUNT];
} Floorplans;

Floorplan *Floorplans::plans[LEVEL_COUNT]{
    new (Floorplan){
      rooms : {
          new (Rectangle){OUTER_BUFFER, OUTER_BUFFER, 6.f, 6.f},             // room 1
          new (Rectangle){OUTER_BUFFER + 6.f, OUTER_BUFFER + 1.f, 3.f, 2.f}, // room 1

          new (Rectangle){OUTER_BUFFER + 9.f, OUTER_BUFFER + 1.f, 10.f, 7.f},  // room 2
          new (Rectangle){OUTER_BUFFER + 15.f, OUTER_BUFFER + 8.f, 3.f, 2.f},  // room 2
          new (Rectangle){OUTER_BUFFER + 15.f, OUTER_BUFFER + 10.f, 8.f, 2.f}, // room 2
          new (Rectangle){OUTER_BUFFER + 21.f, OUTER_BUFFER + 12.f, 2.f, 2.f}, // room 2

          new (Rectangle){OUTER_BUFFER + 18.f, OUTER_BUFFER + 14.f, 8.f, 5.f}, // room 3

          new (Rectangle){OUTER_BUFFER + 24.f, OUTER_BUFFER + 9.f, 22.f, 5.f},   // room 4
          new (Rectangle){OUTER_BUFFER + 36.f, OUTER_BUFFER - 10.f, 10.f, 14.f}, // room 4
          new (Rectangle){OUTER_BUFFER + 46.f, OUTER_BUFFER, 12.f, 4.f},         // room 4
          new (Rectangle){OUTER_BUFFER + 54.f, OUTER_BUFFER + 10.f, 5.f, 3.f},   // room 4
          new (Rectangle){OUTER_BUFFER + 52.f, OUTER_BUFFER + 13.f, 16.f, 6.f},  // room 4
      },
    },
};

// ROOM 1, 9, and 11 are needed

#endif
