#ifndef UNDO_h
#define UNDO_h
#include "Arduino.h"
#include "GAME_LEDs.h"
#include "GameState.h"
#include "GameTimer.h"
#include "History.h"
#include "Logger.h"
#include "POINT_LEDs.h"
#include "PinInterface.h"
#include "SERVE_LEDs.h"
#include "SET_LEDs.h"
#include "TieLeds.h"

class Undo {
 public:
  Undo(Player* player1,
       Player* player2,
       PinInterface* pinInterface,
       GameState* gameState);
  ~Undo();
  void setMode1Undo(History* history);
  void memory();
  void mode1Undo(History* history);

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  ServeLeds _serveLeds;
  TieLeds _tieLeds;
  Logger* _logger;
};

#endif
