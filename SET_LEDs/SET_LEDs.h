//
// class SetLeds
//
#ifndef SET_LEDS_H
#define SET_LEDS_H

#include "Arduino.h"
#include "PinInterface.h"
#include "Player.h"

class SetLeds {
 public:
  SetLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~SetLeds();
  void updateSets();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
};

#endif
