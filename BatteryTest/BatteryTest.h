#ifndef BatteryTest_h
#define BatteryTest_h
#include "Arduino.h"
#include "Player.h"
#include "PinInterface.h"
#include "POINT_LEDs.h"
#include "WatchTimer.h"
#include "INPUTS.h"

class BatteryTest {
 public:
  BatteryTest( Player* player1, Player* player2, PinInterface* pinInterface, PointLeds* pointLeds, Inputs* inputs );
  ~BatteryTest();
  void execute();

private:
  Player*        _player1;
  Player*        _player2;
  PinInterface*  _pinInterface;
  PointLeds*     _pointLeds;
  Inputs*        _inputs;
  WatchTimer     _watchTimer;
  
  void turnLedsOn( int ledOne, int ledTwo, int ledThree, int ledFour, int ledFive, int ledSix );
  void turnLedsOff();
  int  flashLeds( int ledOne, int ledTwo, int ledThree, int ledFour, int ledFive, int ledSix );
};

#endif
