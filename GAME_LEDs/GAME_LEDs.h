#ifndef GAME_LEDs_HEADER_H
#define GAME_LEDs_HEADER_H

#include "DIGI_V6_15.h"
#include "PinInterface.h"
#include "Player.h"
#include "Arduino.h"

class GameLeds {
 public:
  GameLeds(Player* player1, Player* player2, PinInterface* pinInterface);
  ~GameLeds();
  void updateGames();

 private:
  Player* _player1;
  Player* _player2;
  PinInterface* _pinInterface;
};

#endif
