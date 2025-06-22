#ifndef LEVEL
#define LEVEL

#include "raylib.h"

#include "globals.h"
#include "game_state.h"
#include "input.h"
#include "actor.h"
#include "map.h"
#include "trap.h"
#include "enemy.h"
#include "dialogue.h"
#include "interactable.h"

#define TRAP_COUNT 9
#define DIALOGUE_COUNT 7

typedef struct LevelResources
{
  Texture2D playerTexture;
  int startCell;

  Texture2D enemyBlueNTexture;
  Texture2D enemyBlueHTexture;
  Texture2D enemyPinkNTexture;
  Texture2D enemyPinkHTexture;

  Texture2D crushyStoneCleanTexture;
  Texture2D crushyStoneBloodTexture;
  Texture2D spikesEmptyTexture;
  Texture2D spikesHalfTexture;
  Texture2D spikesFullTexture;
  Texture2D baseDoorTexture;

  Sound crushed;
  Sound spiked;
  Sound death;
  Sound footsteps;

  MapResources mapRes;

  Texture2D dialogueBackground;

} LevelResources;

class Level
{
public:
  Level(LevelResources res)
  {
    input = new InputHandler();
    actor = new Actor(res.playerTexture, res.startCell);
    startCell = res.startCell;

    map = new Map(res.mapRes);

    traps[0] = new CrushTrap(res.crushyStoneCleanTexture, res.crushyStoneBloodTexture, res.crushed, FLOOR_SCALE * (4 + 4 * MAP_WIDTH));
    traps[1] = new CrushTrap(res.crushyStoneCleanTexture, res.crushyStoneBloodTexture, res.crushed, FLOOR_SCALE * (8 + 4 * MAP_WIDTH));
    traps[2] = new CrushTrap(res.crushyStoneCleanTexture, res.crushyStoneBloodTexture, res.crushed, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[3] = new CrushTrap(res.crushyStoneCleanTexture, res.crushyStoneBloodTexture, res.crushed, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[4] = new CrushTrap(res.crushyStoneCleanTexture, res.crushyStoneBloodTexture, res.crushed, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));

    traps[5] = new SpikeTrap(res.spikesEmptyTexture, res.spikesFullTexture, res.spiked, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[6] = new SpikeTrap(res.spikesEmptyTexture, res.spikesFullTexture, res.spiked, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[7] = new SpikeTrap(res.spikesEmptyTexture, res.spikesFullTexture, res.spiked, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[8] = new SpikeTrap(res.spikesEmptyTexture, res.spikesFullTexture, res.spiked, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[9] = new SpikeTrap(res.spikesEmptyTexture, res.spikesFullTexture, res.spiked, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));
    traps[10] = new SpikeTrap(res.spikesEmptyTexture, res.spikesFullTexture, res.spiked, FLOOR_SCALE * (12 + 4 * MAP_WIDTH));

    std::vector<int> points = {
        FLOOR_SCALE * (7 + 5 * MAP_WIDTH),
        FLOOR_SCALE * (10 + 7 * MAP_WIDTH),
        FLOOR_SCALE * (10 + 9 * MAP_WIDTH),
        FLOOR_SCALE * (7 + 11 * MAP_WIDTH),
    };
    enemy = new Enemy(res.enemyTexture, FLOOR_SCALE * (5 + 5 * MAP_WIDTH), points);

    dialogue = new Dialogue(res.background);

    orbs[0] = new Interactable(FLOOR_SCALE * (5 + 5 * MAP_WIDTH), "Interaction tutorials!");
    orbs[1] = new Interactable(FLOOR_SCALE * (14 + 4 * MAP_WIDTH), "Dear Diary, We're fucked.");
    orbs[2] = new Interactable(FLOOR_SCALE * (24 + 17 * MAP_WIDTH), "I'm the death god - I hope you suffer.");
    orbs[3] = new Interactable(FLOOR_SCALE * (40 + 12 * MAP_WIDTH), "Dear Diary, I hope I don't get crushed.");
    orbs[4] = new Interactable(FLOOR_SCALE * (36 + 25 * MAP_WIDTH), "I can't find the end...");
    orbs[5] = new Interactable(FLOOR_SCALE * (66 + 100 * MAP_WIDTH), "WELCOME TO THE PIT!!");
    orbs[6] = new Interactable(FLOOR_SCALE * (80 + 94 * MAP_WIDTH), "ITS NOT FAIR ITS NOT FAIR");
  }
  void update();
  void draw();
  void draw2D();

  Vector2 getPlayerPosition();

private:
  InputHandler *input;
  Actor *actor;
  int startCell;

  Map *map;

  Trap *traps[TRAP_COUNT];
  Enemy *enemy;

  Dialogue *dialogue;
  Interactable *orbs[DIALOGUE_COUNT];
};

Vector2 TestCollisions::getPlayerPosition()
{
  return actor->position;
}

#endif
