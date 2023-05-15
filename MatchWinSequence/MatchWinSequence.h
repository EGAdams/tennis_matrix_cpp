#ifndef MatchWinSequence_h
#define MatchWinSequence_h

#include "Arduino.h"
#include "DIGI_V6_15.h"
#include "Player.h"
#include "GameState.h"
#include "GAME_LEDs.h"
#include "GameTimer.h"
#include "SET_LEDs.h"

class MatchWinSequence {
    
 public:
  MatchWinSequence();
  ~MatchWinSequence();
  void run( Player* player, GameState* gameState, GameLeds* gameLeds, SetLeds* setLeds );

 private:

};
#endif
