#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "PinState.h"
#include "Arduino.h"


class PinInterface {
 public:
  PinInterface(PinState* pinState);
  ~PinInterface();
  void pinAnalogWrite(int pin, int value);
  void pinDigitalWrite(int pin, int value);
  int pinAnalogRead(int pin);
  int pinDigitalRead(int pin);
  #if defined _WIN32 || defined _WIN64
  std::map<std::string, int> getPinStateMap();
  #endif
 private:
    #if defined _WIN32 || defined _WIN64
    std::map<std::string, int> _pin_map;
    #endif
    PinState* _pinState;
};

#endif
