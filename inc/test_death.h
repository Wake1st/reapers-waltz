// #ifndef TEST_DEATH
// #define TEST_DEATH

// #include <map>
// #include "raylib.h"

// #include "game_state.h"
// #include "input.h"
// #include "actor.h"
// #include "trap.h"

// typedef struct TestDeathResources
// {
//   Texture2D playerTexture;
//   Texture2D crushyStoneTexture;
// } TestDeathResources;

// class TestDeath
// {
// public:
//   TestDeath(TestDeathResources res)
//   {
//     actor = new Actor(res.playerTexture, 4 + 4 * MAP_WIDTH);
//     input = new InputHandler();

//     traps = {
//         {4 + 5 * MAP_WIDTH, new Trap(res.crushyStoneTexture, 4 + 5 * MAP_WIDTH)},
//         {6 + 8 * MAP_WIDTH, new Trap(res.crushyStoneTexture, 6 + 8 * MAP_WIDTH)},
//         {8 + 11 * MAP_WIDTH, new Trap(res.crushyStoneTexture, 8 + 11 * MAP_WIDTH)},
//     };
//   }

//   void update();
//   void draw();

// private:
//   InputHandler *input;
//   Actor *actor;

//   std::map<int, Trap * trap> traps;
// };

// void TestDeath::update()
// {
//   if (GameState::active == GameStates::DEATH)
//   {
//     // create new actor
//     actor = new Actor(res.playerTexture, 4 + 4 * MAP_WIDTH);

//     // reset traps
//     for (const auto &pair : traps)
//     {
//       pair.second->activate(false);
//     }
//   }

//   Command command = input->handleInput();
//   if (command && !actor->canMove())
//   {
//     actor->move(&command);
//   }

//   // check for traps
//   for (const auto &[cell, trap] : traps)
//   {
//     if (actor->currentCell == cell)
//     {
//       GameState::setState(GameStates::DEATH);
//       trap->activate();
//       actor->isFrozen = true;
//     }
//   }

//   actor->update();
// }

// void TestDeath::draw()
// {
//   actor->draw();

//   for (const auto &pair : traps)
//   {
//     pair.second->draw();
//   }
// }

// #endif
