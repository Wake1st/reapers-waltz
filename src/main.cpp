#include "raylib.h"

#include "test_movement.h"
#include "test_map.h"
#include "test_collisions.h"
#include "test_animations.h"
#include "test_death.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 1800;
  const int screenHeight = 850;

  InitWindow(screenWidth, screenHeight, "Reapers Waltz");
  SetWindowMonitor(0);

  // Texture loading
  Texture2D playerTexture = LoadTexture("resources/pc_sprite_sheet.png");
  Texture2D crushyStoneTexture = LoadTexture("resources/Crushy Crushy Stone.png");

  SetTargetFPS(FRAME_RATE); // Set our game to run at 60 frames-per-second
  //---------------------------------------------------------------------------------------

  // TestMovement *test = new TestMovement(TestMovementResources{texture : playerTexture});
  // TestMap *test = new TestMap(TestMapResources{mapRes : MapResources{
  //   wallTexture : playerTexture,
  //   floorTexture : playerTexture,
  // }});
  // TestCollisions *test = new TestCollisions(TestCollisionsResources{
  //   playerTexture : playerTexture,
  //   mapRes : MapResources{
  //     wallTexture : playerTexture,
  //     floorTexture : playerTexture,
  //   }
  // });
  // TestAnimations *test = new TestAnimations(TestAnimationResources{
  //   playerTexture : playerTexture,
  // });
  TestDeath *test = new TestDeath(TestDeathResources{
    playerTexture : playerTexture,
    crushyStoneTexture : crushyStoneTexture,
  });

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    test->update();

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(BLACK);

    test->draw();

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  // Texture unloading
  UnloadTexture(playerTexture);
  UnloadTexture(crushyStoneTexture);

  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}