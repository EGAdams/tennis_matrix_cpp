#ifndef GAME_MODES_h
#define GAME_MODES_h
#include "Arduino.h"
#include "DIGI_V6_15.h"
#include "GAME_LEDs.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
// #include "IniReader.h"
#include "Logger.h"
#include "MODE_1_FUNCTIONS.h"
#include "MODE_1_TIEBREAKER.h"
#include "MODE_2_FUNCTIONS.h"
#include "POINT_LEDs.h"
#include "PinInterface.h"
#include "Player.h"
#include "SERVE_LEDs.h"
#include "SET_LEDs.h"
#include "UNDO.h"
#include "WatchTimer.h"
#include "BatteryTest.h"

class History;

#if defined _WIN32 || defined _WIN64
    #include <iostream>
#endif
class GameModes {
 public:
  GameModes(Player* player1,
            Player* player2,
            PinInterface* pinInterface,
            GameState* gameState,
            History* history);
  ~GameModes();
  void gameStart();
  void testStart();
  void mode1();
  void mode2();
  void mode4();
  void noCode();
  void setGameMode(int rotaryPosition);

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  History* _history;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  SetLeds _setLeds;
  Inputs _inputs;
  Undo _undo;
  ServeLeds _serveLeds;
  Mode1TieBreaker _mode1TieBreaker;
  Mode1Functions _mode1Functions;
  Mode2Functions _mode2Functions;
  //   IniReader _iniReader;
  Logger* _logger;
};

#endif
