//
// class TieLeds
//
#ifndef TIE_LEDS_H
#define TIE_LEDS_H

#include "Arduino.h"
#include "PinInterface.h"

class TieLeds {
 public:
  TieLeds(PinInterface* pinInterface);
  ~TieLeds();
  void turnOff();
  void turnOn();

 private:
  PinInterface* _pinInterface;
};

#endif
