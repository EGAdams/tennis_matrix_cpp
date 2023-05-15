#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Arduino.h"
#include "Player.h"
#include "DIGI_V6_15.h"

class GameState {
 public:
  GameState();
  ~GameState();
  void setWinDelay(int winDelay);
  int getWinDelay();
  void setPointFlash(int pointFlash);
  int getPointFlash();
  void setServe(int serve);
  int getServe();
  void setTieBreak(int tieBreak);
  int getTieBreak();
  void setTieLEDsOn(int tieLEDsOn);
  int getTieLEDsOn();
  void setServeSwitch(int serveSwitch);
  int getServeSwitch();
  void setPlayerButton(int playerButton);
  int getPlayerButton();
  void setUndo(int undo);
  int getUndo();
  void setStarted(int started);
  int getStarted();
  void setSetTieBreak(int setTieBreak);
  int getSetTieBreak();
  void setRotaryChange(int rotaryChange);
  int getRotaryChange();
  void setPreviousTime(unsigned long previousTime);
  int getRotaryPosition();
  void setRotaryPosition(int rotaryPosition);
  int getPrevRotaryPosition();
  void setPrevRotaryPosition(int prevRotaryPosition);
  unsigned long getPreviousTime();
  int getFreezePlayerButton();
  void setFreezePlayerButton(int freezePlayerButton);
  void setP1PointsMem(int p1PointsMem);
  int getP1PointsMem();
  void setP2PointsMem(int p2PointsMem);
  int getP2PointsMem();
  void setP1GamesMem(int p1GamesMem);
  int getP1GamesMem();
  void setP2GamesMem(int p2GamesMem);
  int getP2GamesMem();
  void setP1SetsMem(int p1SetsMem);
  int getP1SetsMem();
  void setP2SetsMem(int p2SetsMem);
  int getP2SetsMem();
  void setNow(unsigned long now);
  unsigned long getNow();
  void setToggle(int toggle);
  int getToggle();
  int getTieBreakOnly();
  void setTieBreakOnly(int tieBreakOnly);
  void setButtonDelay(int buttonDelay);
  int getButtonDelay();
  void setFlashDelay(unsigned long flashDelay);
  unsigned long getFlashDelay();
  void setGameWinPulseCount(int gameWinPulseCount);
  int getGameWinPulseCount();
  void setTieBreakMem(int tieBreakMem);
  int getTieBreakMem();
  void setSetTieBreakMem(int setTieBreakMem);
  int getSetTieBreakMem();
  void setGameFlashDelay(int gameFlashDelay);
  int getGameFlashDelay();
  int getPlayer1Points();
  void setPlayer1Points(int player1Points);
  int getPlayer2Points();
  void setPlayer2Points(int player2Points);
  int getPlayer1Games();
  void setPlayer1Games(int player1Games);
  int getPlayer2Games();
  void setPlayer2Games(int player2Games);
  int getPlayer1Sets();
  void setPlayer1Sets(int player1Sets);
  int getPlayer2Sets();
  void setPlayer2Sets(int player2Sets);
  int getPlayer1Matches();
  void setPlayer1Matches(int player1Matches);
  int getPlayer2Matches();
  void setPlayer2Matches(int player2Matches);

 private:
  int _player1_points;
  int _player2_points;
  int _player1_games;
  int _player2_games;
  int _player1_sets;
  int _player2_sets;
  int _player1_matches;
  int _player2_matches;
  int _pointFlash;
  int _serve;
  int _tieBreak;
  int _setTieBreak;
  int _tieLEDsOn;
  int _started;
  int _serveSwitch;
  int _playerButton;
  int _undo;
  int _rotaryPosition;
  int _prevRotaryPosition;
  int _rotaryChange;
  unsigned long _now;
  unsigned long _previousTime;
  int _freezePlayerButton;
  int _p1PointsMem;
  int _p2PointsMem;
  int _p1GamesMem;
  int _p2GamesMem;
  int _p1SetsMem;
  int _p2SetsMem;
  int _toggle;
  int _tieBreakOnly;
  int _winDelay;              // = 100;
  int _buttonDelay;           // = 100;
  unsigned long _flashDelay;  // = 1000;
  int _gameFlashDelay;      // = 750;  // still experimenting with this value...
  int _gameWinPulseCount;   // = 0 /* 3 */;
  int _setTieBreakMem;
  int _tieBreakMem;
};

#endif
