#include "POINT_LEDs.h"
#include "Arduino.h"
#include "DIGI_V6_15.h"

PointLeds::PointLeds( Player* player1,
    Player* player2,
    PinInterface* pinInterface )
    : _player1( player1 ), _player2( player2 ), _pinInterface( pinInterface ) {}

PointLeds::~PointLeds() {}

void PointLeds::updatePoints() {
    #if defined _WIN32 || defined _WIN64
        std::cout << "updatePoints() called.  player 1 points: " << std::endl;
    #endif
    switch ( _player1->getPoints() ) {
    case 0:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, HIGH );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, LOW );
        break;
    case 1:
        #if defined _WIN32 || defined _WIN64
            std::cout << "player has 1 point!" << std::endl;
        #endif
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, HIGH );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, LOW );
        break;
    case 2:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, HIGH );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, LOW );
        break;
    case 3:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, HIGH );
        break;
    case 4:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, HIGH );
        break;
    case 5:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, HIGH );
        break;

    case 99:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, LOW );
        #if defined _WIN32 || defined _WIN64
            _pinInterface->pinDigitalWrite( P1_POINTS_LED4, BLINK );
        #endif  
        break;

    case 100:
        _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P1_POINTS_LED4, LOW );
        break;
    }

    switch ( _player2->getPoints() ) {
    case 0:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, HIGH );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, LOW );
        break;
    case 1:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, HIGH );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, LOW );
        break;
    case 2:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, HIGH );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, LOW );
        break;
    case 3:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, HIGH );
        break;
    case 4:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, HIGH );
        break;
    case 5:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, HIGH );
        break;
    case 99:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, LOW );
        #if defined _WIN32 || defined _WIN64
            _pinInterface->pinDigitalWrite( P2_POINTS_LED4, BLINK );
        #endif    
        break;

    case 100:
        _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
        _pinInterface->pinDigitalWrite( P2_POINTS_LED4, LOW );   
        break;
    }
}

void PointLeds::updateTBPoints() {
    _pinInterface->pinDigitalWrite( P1_POINTS_LED1, LOW );
    _pinInterface->pinDigitalWrite( P1_POINTS_LED2, LOW );
    _pinInterface->pinDigitalWrite( P1_POINTS_LED3, LOW );
    _pinInterface->pinDigitalWrite( P1_POINTS_LED4, LOW );
    _pinInterface->pinDigitalWrite( P2_POINTS_LED1, LOW );
    _pinInterface->pinDigitalWrite( P2_POINTS_LED2, LOW );
    _pinInterface->pinDigitalWrite( P2_POINTS_LED3, LOW );
    _pinInterface->pinDigitalWrite( P2_POINTS_LED4, LOW );
}
