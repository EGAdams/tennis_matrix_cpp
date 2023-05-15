#include "PinInterface.h"
#include "Arduino.h"

PinInterface::PinInterface( PinState* pinState ) : _pinState( pinState ) {}
PinInterface::~PinInterface() {}

int PinInterface::pinAnalogRead( int pin ) {
#if defined _WIN32 || defined _WIN64
    int pin_value = _pinState->getPinState( std::to_string( pin ) );
    std::cout << "analog read pin_value: " << pin_value << std::endl;
#else
    int pin_value = analogRead( pin );
#endif
    return pin_value;
}

int PinInterface::pinDigitalRead( int pin ) {
#if defined _WIN32 || defined _WIN64
    int pin_value = _pinState->getPinState( std::to_string( pin ) );
    // std::cout << "digital read pin_value: " << pin_value << std::endl;
#else
    int pin_value = digitalRead( pin );
#endif
    return pin_value;
}

void PinInterface::pinAnalogWrite( int pin, int value ) {
#if defined _WIN32 || defined _WIN64
    _pinState->setPinState( std::to_string( pin ), value );
#else
    analogWrite( pin, value );
#endif
}

void PinInterface::pinDigitalWrite( int pin, int value ) {
#if defined _WIN32 || defined _WIN64
    // std::cout << "setting pin " << pin << " to " << value << std::endl;
    _pinState->setPinState( std::to_string( pin ), value );
#else
    digitalWrite( pin, value );
#endif
}

#if defined _WIN32 || defined _WIN64
std::map<std::string, int> PinInterface::getPinStateMap() {
    return _pin_map;
}
#endif
