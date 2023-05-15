#ifndef MODE_2_FUNCTIONS_h
#define MODE_2_FUNCTIONS_h
#include "GAME_LEDs.h"
#include "GameState.h"
#include "GameTimer.h"
#include "POINT_LEDs.h"
#include "Player.h"
#include "SET_LEDs.h"
#include "Arduino.h"

class Mode2Functions {
 public:
  Mode2Functions(Player* player1,
                 Player* player2,
                 PinInterface* pinInterface,
                 GameState* gameState);
  ~Mode2Functions();
  void m2Loop();
  void m2PlayerButtons(int playerButton);

 private:
  Player* _player1;
  Player* _player2;
  GameState* _gameState;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
};

#endif
