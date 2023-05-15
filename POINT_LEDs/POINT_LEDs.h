#ifndef POINT_LEDS_h
#define POINT_LEDS_h

#include "GameState.h"
#include "PinInterface.h"
#include "Player.h"
#include "Arduino.h"

class PointLeds {
 public:
  PointLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~PointLeds();
  void updatePoints();
  void updateTBPoints();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
};

#endif
