#ifndef SERVE_LEDS_h
#define SERVE_LEDS_h

#include "GameState.h"
#include "PinInterface.h"
#include "Arduino.h"

class ServeLeds {
 public:
  ServeLeds(PinInterface* pinInterface, GameState* gameState);
  ~ServeLeds();
  void updateServeLED();
  void serveSwitch();

 private:
  PinInterface* _pinInterface;
  GameState* _gameState;
};

#endif
