#include "PinState.h"
#include "Arduino.h"

#if defined _WIN32 || defined _WIN64
PinState::PinState( std::map< std::string, int > pin_map ) : _pin_map( pin_map ) {}
#else
PinState::PinState() {}
#endif
PinState::~PinState() {}

#if defined _WIN32 || defined _WIN64
int PinState::getPinState( std::string pin ) {
    #if defined _WIN32 || defined _WIN64
    std::cout << "Translating constant for pin: " << pin << std::endl;
    if ( _translateConstant.get_translated_constant( std::stoi( pin ) ) == "ROTARY" ) {     
        std::string pin_file_path = "C:\\Users\\EG\\Desktop\\2022\\june\\2nd_week\\tennis_cpp\\pin_data\\";
        std::cout << "translating pin: " << pin << "... " << std::endl;
        std::ifstream pin_file( pin_file_path + _translateConstant.get_translated_constant( std::stoi( pin ) ) + ".txt" );
        pin_file >> pin;
        pin_file.close();
        std::cout << "got pin " << pin << " from file" << std::endl;
        return std::stoi( pin );
    } else {
        std::cout << "translated constant: " << _translateConstant.get_translated_constant( std::stoi( pin ) ) << std::endl;
    }
    #endif
    return _pin_map[ pin ];
}

void PinState::setPinState( std::string pin, int state ) {
    _pin_map[ pin ] = state;
    std::string pin_file_path = "C:\\Users\\EG\\Desktop\\2022\\june\\2nd_week\\tennis_cpp\\pin_data\\";
    std::ofstream pin_file( pin_file_path + _translateConstant.get_translated_constant( std::stoi( pin ) ) + ".txt" );
    pin_file << state;
    pin_file.close();
}
#endif

void PinState::clear() {
#if defined _WIN32 || defined _WIN64    
    _pin_map.clear();
#endif
}

#if defined _WIN32 || defined _WIN64
std::map<std::string, int> PinState::getMap() {
    return _pin_map;
}
#endif
