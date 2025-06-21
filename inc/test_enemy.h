#ifndef TEST_ENEMY
#define TEST_ENEMY

#include <vector>
#include "raylib.h"

#include "globals.h"
#include "enemy.h"

typedef struct TestEnemyResources
{
  Texture2D enemyTexture;
  Texture2D playerTexture;
} TestEnemyResources;

class TestEnemy
{
public:
  TestEnemy(TestEnemyResources res)
  {
    std::vector<int> points = {
        7 + 5 * MAP_WIDTH,
        10 + 7 * MAP_WIDTH,
        10 + 9 * MAP_WIDTH,
        7 + 11 * MAP_WIDTH,
        5 + 11 * MAP_WIDTH,
        2 + 9 * MAP_WIDTH,
        2 + 7 * MAP_WIDTH,
        5 + 5 * MAP_WIDTH,
    };
    enemy = new Enemy(res.enemyTexture, 5 + 5 * MAP_WIDTH, points);

    input = new InputHandler();
    player = new Actor(res.playerTexture, 18 + 26 * MAP_WIDTH);
  }
  void update();
  void draw();

private:
  Enemy *enemy;

  InputHandler *input;
  Actor *player;
};

void TestEnemy::update()
{
  Command command = input->handleInput();
  if (command)
  {
    player->move(&command);
  }

  player->update();
  enemy->update();
}

void TestEnemy::draw()
{
  player->draw();
  enemy->draw();
}

#endif
