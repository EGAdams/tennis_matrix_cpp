#ifndef PINSTATE_H
#define PINSTATE_H

#include "Arduino.h"

#if defined _WIN32 || defined _WIN64
#include <map>
#include <fstream>
#include "TranslateConstant.h"
#endif

class PinState {
public:
#if defined _WIN32 || defined _WIN64
    PinState( std::map< std::string, int > pinMap );
#else
    PinState();
#endif
    ~PinState();
#if defined _WIN32 || defined _WIN64
    void setPinState( std::string pin, int state );
    int getPinState( std::string pin );
#endif
    void clear();
#if defined _WIN32 || defined _WIN64
    std::map<std::string, int> getMap();
#endif

private:
#if defined _WIN32 || defined _WIN64
    std::map< std::string, int > _pin_map;
    TranslateConstant _translateConstant;
#endif
};

#endif
