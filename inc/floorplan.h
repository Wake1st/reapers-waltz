#ifndef FLOORPLAN
#define FLOORPLAN

#include "raylib.h"

#include "globals.h"

#define ROOM_COUNT 24
#define ROOMS_PER_LEVEL 7

typedef struct Floorplan
{
  Rectangle *rooms[ROOMS_PER_LEVEL];
} Floorplan;

typedef struct Floorplans
{
  static Floorplan *plans[LEVEL_COUNT];
} Floorplans;

Floorplan *Floorplans::plans[LEVEL_COUNT]{
    new (Floorplan){rooms : {
        new (Rectangle){OUTER_BUFFER, OUTER_BUFFER, 6.f, 6.f},               // room 1
        new (Rectangle){OUTER_BUFFER + 6.f, OUTER_BUFFER + 1.f, 3.f, 2.f},   // hall 1
        new (Rectangle){OUTER_BUFFER + 9.f, OUTER_BUFFER + 1.f, 10.f, 7.f},  // room 2
        new (Rectangle){OUTER_BUFFER + 15.f, OUTER_BUFFER + 8.f, 3.f, 2.f},  // hall 2
        new (Rectangle){OUTER_BUFFER + 15.f, OUTER_BUFFER + 10.f, 8.f, 2.f}, // hall 3
        new (Rectangle){OUTER_BUFFER + 21.f, OUTER_BUFFER + 12.f, 2.f, 2.f}, // hall 4
        new (Rectangle){OUTER_BUFFER + 18.f, OUTER_BUFFER + 14.f, 8.f, 5.f}, // room 3
    }},
};

// static class Floorplans
// {
// public:
//   static Floorplan *plans[LEVEL_COUNT]{
//       new (Floorplan){rooms : {
//           new (Rectangle){OUTER_BUFFER, OUTER_BUFFER, 6.f, 6.f},               // room 1
//           new (Rectangle){OUTER_BUFFER + 6.f, OUTER_BUFFER + 1.f, 3.f, 2.f},   // hall 1
//           new (Rectangle){OUTER_BUFFER + 9.f, OUTER_BUFFER + 1.f, 10.f, 7.f},  // room 2
//           new (Rectangle){OUTER_BUFFER + 15.f, OUTER_BUFFER + 8.f, 3.f, 2.f},  // hall 2
//           new (Rectangle){OUTER_BUFFER + 15.f, OUTER_BUFFER + 10.f, 8.f, 2.f}, // hall 3
//           new (Rectangle){OUTER_BUFFER + 21.f, OUTER_BUFFER + 12.f, 2.f, 2.f}, // hall 4
//           new (Rectangle){OUTER_BUFFER + 18.f, OUTER_BUFFER + 14.f, 8.f, 5.f}, // room 3
//       }},
//   };
// };

#endif
