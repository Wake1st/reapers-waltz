#ifndef GAME_STATE
#define GAME_STATE

typedef enum GameStates
{
  START,  // start menu
  INTRO,  // opening cinematic
  SETUP,  // initial setup
  PLAY,   // active playing
  PAUSE,  // pause menu
  DEATH,  // death animations
  FINALE, // final sequence
  OUTRO,  // exiting cinematic?
  END,    // fin, credits
} GameSates;

class GameState
{
public:
  static GameStates active;

  static setState(GameStates state)
  {
    active = state;
  }
}

#endif
