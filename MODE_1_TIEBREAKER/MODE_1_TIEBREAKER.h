#ifndef MODE_1_TIEBREAKER_H
#define MODE_1_TIEBREAKER_H
#include "Arduino.h"
#include "GAME_LEDs.h"
#include "GameState.h"
#include "MODE_1_WIN_SEQUENCES.h"
#include "POINT_LEDs.h"
#include "PinInterface.h"
#include "Player.h"
#include "SERVE_LEDs.h"
#include "SET_LEDs.h"
#include "UNDO.h"
#include "WatchTimer.h"

class Mode1TieBreaker {
 public:
  Mode1TieBreaker(Player* player1,
                  Player* player2,
                  PinInterface* pinInterface,
                  GameState* gameState,
                  History* history);
  ~Mode1TieBreaker();
  void tieBreaker();
  void setTieBreaker();
  void mode1TBButtonFunction();
  void mode1SetTBButtonFunction();
  void tieBreakEnable();
  void setTieBreakEnable();
  void tieLEDsOn();
  void tieLEDsOff();
  void endTieBreak();

  // from mode 1 score
  void mode1TBP1Games();
  void mode1TBP2Games();
  void mode1SetTBP2Games();
  void mode1SetTBP1Games();

  // from mode 1 win sequences
  // void p1TBSetWinSequence();
  // void p1SetWinSequence();
  // void p2TBSetWinSequence();
  // void p2SetWinSequence();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
  GameState* _gameState;
  History* _history;
  PointLeds _pointLeds;
  GameLeds _gameLeds;
  ServeLeds _serveLeds;
  SetLeds _setLeds;
  Mode1WinSequences _mode1WinSequences;
  Undo _undo;
};

#endif
