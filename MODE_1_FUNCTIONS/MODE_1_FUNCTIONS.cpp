#include "MODE_1_FUNCTIONS.h"
#include "Arduino.h"
#include "DIGI_V6_15.h"

Mode1Functions::Mode1Functions( Player* player1,
    Player* player2,
    PinInterface* pinInterface,
    GameState* gameState,
    History* history )
    : _player1( player1 ),
    _player2( player2 ),
    _gameState( gameState ),
    _history( history ),
    _undo( player1, player2, pinInterface, gameState ),
    _pointLeds( player1, player2, pinInterface ),
    _mode1Score( player1, player2, pinInterface, gameState, history ),
    _serveLeds( pinInterface, gameState ) {}

Mode1Functions::~Mode1Functions() {}

void Mode1Functions::mode1ButtonFunction() {
    switch ( _gameState->getPlayerButton() ) {
    case 0:
        break;

    case 1: // Player 1 Score
        #if defined _WIN32 || defined _WIN64
            std::cout << "player 1 scored.  setting mode 1 undo..." << std::endl;
        #endif
        _undo.setMode1Undo( _history );
        if ( _gameState->getPointFlash() == 1 ) {
            _gameState->setPointFlash( 0 );
            _player1->setPoints( _gameState->getP1PointsMem() );
            _player2->setPoints( _gameState->getP2PointsMem() ); 
            _pointLeds.updatePoints();
        }
        GameTimer::gameDelay( _gameState->getButtonDelay() );
        _player1->setPoints( _player1->getPoints() + 1 );
        _undo.memory();
        _mode1Score.mode1P1Score();
        break;

    case 2: // UNDO button pressed
        GameTimer::gameDelay( _gameState->getButtonDelay() );
        _undo.mode1Undo( _history );  // Mode1Undo();
        break;

    case 3: // Player 2 Score
        _undo.setMode1Undo( _history );
        if ( _gameState->getPointFlash() == 1 ) {
            _gameState->setPointFlash( 0 );  
            _player1->setPoints( _gameState->getP1PointsMem() ); 
            _player2->setPoints( _gameState->getP2PointsMem() ); 
            _pointLeds.updatePoints();                            
        }
        GameTimer::gameDelay( _gameState->getButtonDelay() );
        _player2->setPoints( _player2->getPoints() + 1 );  
        _undo.memory();                                 
        _mode1Score.mode1P2Score();                      
        break;

    case 4:
        GameTimer::gameDelay( _gameState->getButtonDelay() );
        _undo.mode1Undo( _history );
        break;
    }
    _gameState->setPlayerButton( 0 );
}

void Mode1Functions::mode1ServeFunction() {
    _undo.setMode1Undo( _history );
    _serveLeds.serveSwitch();
}

void Mode1Functions::pointFlash() {
    if ( _gameState->getPointFlash() == 1 ) {
        if ( _player1->getPoints() > 3 ) {
            #if defined _WIN32 || defined _WIN64
                _player1->setPoints( 99 );
                _pointLeds.updatePoints();
            #else
            if ( _gameState->getNow() - _gameState->getPreviousTime() > _gameState->getFlashDelay() ) {
                if ( _gameState->getToggle() == 0 ) {
                    _player1->setPoints( 99 );      // turn  4th LED off
                    _pointLeds.updatePoints();  
                    _gameState->setToggle( 1 );
                }
                else {
                    _player1->setPoints(
                    _gameState->getP1PointsMem() ); // turn 4th LED on
                    _pointLeds.updatePoints();
                    _gameState->setToggle( 0 );
                }
                _gameState->setPreviousTime( _gameState->getNow() );
            }
            #endif
        }
        
        if ( _player2->getPoints() > 3 ) {
            #if defined _WIN32 || defined _WIN64
                _player2->setPoints( 99 );
                _pointLeds.updatePoints();
            #else
                if ( _gameState->getNow() - _gameState->getPreviousTime() > _gameState->getFlashDelay() ) {
                    if ( _gameState->getToggle() == 0 ) {
                        _player2->setPoints( 99 );      // turn  4th LED off
                        _pointLeds.updatePoints();
                        _gameState->setToggle( 1 );
                    } else {
                        _player2->setPoints(
                        _gameState->getP2PointsMem() ); // turn 4th LED on
                        _pointLeds.updatePoints(); 
                        _gameState->setToggle( 0 ); 
                    }
                    _gameState->setPreviousTime( _gameState->getNow() ); 
                }
            #endif
        }
    }
}
