#ifndef GameWinSequence_h
#define GameWinSequence_h

#include "Arduino.h"
#include "Player.h"
#include "GameState.h"
#include "GAME_LEDs.h"
#include "GameTimer.h"

class GameWinSequence {
    
 public:
  GameWinSequence();
  ~GameWinSequence();
  void run( Player* player, GameState* gameState, GameLeds* gameLeds, int games_in_memory );

 private:

};
#endif
