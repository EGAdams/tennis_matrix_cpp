#ifndef WinSequence_h
#define WinSequence_h

#include "Arduino.h"
#include "Player.h"
#include "GameState.h"
#include "GAME_LEDs.h"
#include "GameTimer.h"

class WinSequence {
    
 public:
  WinSequence();
  ~WinSequence();
  void run( Player* player, GameState* gameState, GameLeds* gameLeds, int games_in_memory );

 private:

};
#endif
