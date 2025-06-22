#include "raylib.h"

#include "globals.h"
#include "test_movement.h"
#include "test_map.h"
#include "test_collisions.h"
#include "test_animations.h"
#include "test_death.h"
#include "test_audio.h"
#include "test_enemy.h"
#include "test_dialogue.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Reapers Waltz");
  InitAudioDevice();

  SetWindowMonitor(0);

  // Resource loading
  Texture2D playerTexture = LoadTexture("resources/pc_sprite_sheet.png");
  Texture2D crushyStoneTexture = LoadTexture("resources/Crushy Crushy Stone.png");
  Texture2D dialogueTexture = LoadTexture("resources/menu_background.png");

  Sound crushOgg = LoadSound("resources/crushed.ogg");
  Sound spikeOgg = LoadSound("resources/spiked.ogg");
  Sound deathOgg = LoadSound("resources/death.ogg");
  Sound stepsOgg = LoadSound("resources/footsteps.ogg");

  // Set our game to run at 60 frames-per-second
  SetTargetFPS(FRAME_RATE);

  //---------------------------------------------------------------------------------------

  int startCell = (OUTER_BUFFER + 3) + (OUTER_BUFFER + 3) * MAP_WIDTH;
  Vector2 playerStart = PositionOfCell(startCell);

  Camera2D camera = {0};
  camera.target = (Vector2){playerStart.x, playerStart.y};
  camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  RenderTexture screenCamera = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

  // TestMovement *test = new TestMovement(TestMovementResources{texture : playerTexture});
  // TestMap *test = new TestMap(TestMapResources{mapRes : MapResources{
  //   wallTexture : playerTexture,
  //   floorTexture : playerTexture,
  // }});
  TestCollisions *test = new TestCollisions(TestCollisionsResources{
    playerTexture : playerTexture,
    startCell : startCell,
    mapRes : MapResources{
      wallTexture : playerTexture,
      floorTexture : playerTexture,
    }
  });
  // TestAnimations *test = new TestAnimations(TestAnimationResources{
  //   playerTexture : playerTexture,
  // });
  // TestDeath *test = new TestDeath(TestDeathResources{
  //   playerTexture : playerTexture,
  //   crushyStoneTexture : crushyStoneTexture,
  // });
  // TestAudio *test = new TestAudio(TestAudioResources{
  //   crushed : crushOgg,
  //   spiked : spikeOgg,
  //   death : deathOgg,
  //   footsteps : stepsOgg,
  // });
  // TestEnemy *test = new TestEnemy(TestEnemyResources{
  //   enemyTexture : playerTexture,
  //   playerTexture : playerTexture,
  // });
  // TestDialogue *test = new TestDialogue(TestDialogueResources{
  //   playerTexture : playerTexture,
  //   background : dialogueTexture,
  // });

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    test->update();

    camera.target = test->getPlayerPosition();

    // Draw
    //----------------------------------------------------------------------------------

    BeginTextureMode(screenCamera);
    ClearBackground(BLACK);

    BeginMode2D(camera);

    test->draw2D();

    EndMode2D();

    DrawText(TextFormat("target X: %f\ttarget Y: %f", camera.target.x, camera.target.y), 20, 180, 20, BLACK);

    EndTextureMode();

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
  UnloadTexture(dialogueTexture);

  UnloadSound(crushOgg);
  UnloadSound(spikeOgg);
  UnloadSound(deathOgg);
  UnloadSound(stepsOgg);

  // Close window and OpenGL context
  UnloadRenderTexture(screenCamera);

  CloseAudioDevice();

  CloseWindow();
  //--------------------------------------------------------------------------------------

  return 0;
}
