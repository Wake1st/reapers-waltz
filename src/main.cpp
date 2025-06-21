#include "raylib.h"

#include "test_movement.h"
#include "test_map.h"
#include "test_collisions.h"
#include "test_animations.h"
#include "test_death.h"
#include "test_audio.h"
#include "test_enemy.h"

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
  InitAudioDevice();

  SetWindowMonitor(0);

  // Resource loading
  Texture2D playerTexture = LoadTexture("resources/pc_sprite_sheet.png");
  Texture2D crushyStoneTexture = LoadTexture("resources/Crushy Crushy Stone.png");

  Sound crushWav = LoadSound("resources/ISEKAI - CRUSHER.wav");
  Sound spikeWav = LoadSound("resources/ISEKAI - SPIKES.wav");
  Sound deathWav = LoadSound("resources/ISEKAI - Death.wav");
  Sound stepsWav = LoadSound("resources/ISEKAI - FOOTSTEPS.wav");

  // Set our game to run at 60 frames-per-second
  SetTargetFPS(FRAME_RATE);

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
  // TestDeath *test = new TestDeath(TestDeathResources{
  //   playerTexture : playerTexture,
  //   crushyStoneTexture : crushyStoneTexture,
  // });
  // TestAudio *test = new TestAudio(TestAudioResources{
  //   crushed : crushWav,
  //   spiked : spikeWav,
  //   death : deathWav,
  //   footsteps : stepsWav,
  // });
  TestEnemy *test = new TestEnemy(TestEnemyResources{
    enemyTexture : playerTexture,
    playerTexture : playerTexture,
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
  // Resource unloading
  UnloadTexture(playerTexture);
  UnloadTexture(crushyStoneTexture);

  UnloadSound(crushWav);
  UnloadSound(spikeWav);
  UnloadSound(deathWav);
  UnloadSound(stepsWav);

  // Close window and OpenGL context
  CloseAudioDevice();

  CloseWindow();
  //--------------------------------------------------------------------------------------

  return 0;
}