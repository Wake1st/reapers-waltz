#include "raylib.h"

#include "globals.h"
#include "level.h"

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
  SetWindowMonitor(0);
  InitAudioDevice();

  // Resource loading
  Texture2D playerTexture = LoadTexture("resources/pc_sprite_sheet.png");
  Texture2D enemyBlueNonTexture = LoadTexture("resources/Enemy_blue_evil_non-hos.png");
  Texture2D enemyBlueHosTexture = LoadTexture("resources/Enemy_blue_evil.png");
  Texture2D enemyPinkNonTexture = LoadTexture("resources/Enemy_pink_evil_non-hos.png");
  Texture2D enemyPinkHosTexture = LoadTexture("resources/Enemy_pink_evil.png");

  Texture2D crushyStoneCleanTexture = LoadTexture("resources/Crushy Crushy Stone.png");
  Texture2D crushyStoneBloodTexture = LoadTexture("resources/Curshy_crushy_stone_w_blood.png");
  Texture2D spikeHolesTexture = Load("resources/Spike_Holes.png");
  Texture2D spikeHalfTexture = Load("resources/Spike_Half.png");
  Texture2D spikeOutBloodTexture = Load("resources/Spike_Out_Blood.png");
  Texture2D groundTexture = Load("resources/Ground_Tile.png");

  Texture2D dialogueTexture = LoadTexture("resources/menu_background.png");

  Sound crushOgg = LoadSound("resources/crushed.ogg");
  Sound spikeOgg = LoadSound("resources/spiked.ogg");
  Sound deathOgg = LoadSound("resources/death.ogg");
  Sound stepsOgg = LoadSound("resources/footsteps.ogg");

  // Set our game to run at 60 frames-per-second
  SetTargetFPS(FRAME_RATE);

  //---------------------------------------------------------------------------------------

  int startCell = FLOOR_SCALE * ((OUTER_BUFFER + 3) + (OUTER_BUFFER + 3) * MAP_WIDTH);
  Vector2 playerStart = PositionOfCell(startCell);

  Camera2D camera = {0};
  camera.target = playerStart;
  camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  // TestMovement *test = new TestMovement(TestMovementResources{texture : playerTexture});
  // TestMap *test = new TestMap(TestMapResources{mapRes : MapResources{
  //   wallTexture : playerTexture,
  //   floorTexture : playerTexture,
  // }});
  // TestCollisions *test = new TestCollisions(TestCollisionsResources{
  //   playerTexture : playerTexture,
  //   startCell : startCell,
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

  Level *level = new Level(LevelResources{
    playerTexture : playerTexture,
    startCell : startCell,
    enemyBlueNTexture : enemyBlueNonTexture,
    enemyBlueHTexture : enemyBlueHosTexture,
    enemyPinkNTexture : enemyPinkNonTexture,
    enemyPinkHTexture : enemyPinkHosTexture,
    crushyStoneCleanTexture : crushyStoneCleanTexture,
    crushyStoneBloodTexture : crushyStoneBloodTexture,
    spikesEmptyTexture : spikeHolesTexture,
    spikesHalfTexture : spikeHalfTexture,
    spikesFullTexture : spikeOutBloodTexture,
    mapRes : MapResources{
      wallTexture : playerTexture,
      floorTexture : groundTexture,
    },
    dialogueBackground : dialogueTexture,
  });

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    test->update();

    camera.offset = (Vector2){SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f};
    camera.target = test->getPlayerPosition();

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);

    test->draw();
    test->draw2D();

    DrawText(TextFormat("target X: %f\ttarget Y: %f", camera.target.x, camera.target.y), 20, 180, 20, BLACK);
    DrawText(TextFormat("offset X: %f\toffset Y: %f", camera.offset.x, camera.offset.y), 20, 220, 20, BLACK);

    EndMode2D();
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  // Resource unloading
  UnloadTexture(playerTexture);
  UnloadTexture(enemyBlueNonTexture);
  UnloadTexture(enemyBlueHosTexture);
  UnloadTexture(enemyPinkNonTexture);
  UnloadTexture(enemyPinkHosTexture);

  UnloadTexture(crushyStoneCleanTexture);
  UnloadTexture(crushyStoneBloodTexture);
  UnloadTexture(spikeHolesTexture);
  UnloadTexture(spikeHalfTexture);
  UnloadTexture(spikeOutBloodTexture);
  UnloadTexture(groundTexture);

  UnloadTexture(dialogueTexture);

  UnloadSound(crushOgg);
  UnloadSound(spikeOgg);
  UnloadSound(deathOgg);
  UnloadSound(stepsOgg);

  // Close window and OpenGL context

  CloseAudioDevice();

  CloseWindow();
  //--------------------------------------------------------------------------------------

  return 0;
}
