#include "GAME_MODES.h"
#include "Arduino.h"
GameModes::~GameModes() {}
GameModes::GameModes( Player* player1,
    Player* player2,
    PinInterface* pinInterface,
    GameState* gameState,
    History* history )
    : _player1( player1 ),
    _player2( player2 ),
    _pinInterface( pinInterface ),
    _gameState( gameState ),
    _history( history ),
    _pointLeds( player1, player2, pinInterface ),
    _gameLeds( player1, player2, pinInterface ),
    _setLeds( player1, player2, pinInterface ),
    _inputs( player1, player2, pinInterface, gameState ),
    _undo( player1, player2, pinInterface, gameState ),
    _serveLeds( pinInterface, gameState ),
    _mode1TieBreaker( player1, player2, pinInterface, gameState, history ),
    _mode1Functions( player1, player2, pinInterface, gameState, history ),
    _mode2Functions( player1, player2, pinInterface, gameState ) {
    _logger = new Logger(
        "C:\\Users\\EG\\Desktop\\2022\\may\\4th_week\\log_viewer_sand\\test.txt" );
}

void GameModes::gameStart() {
    if ( _gameState->getStarted() == 0 ) {  // if not started...
        _player1->setPoints( 0 );             // p1Points = 0;
        _player2->setPoints( 0 );             // p2Points = 0;
        _player1->setGames( 0 );              // p1Games = 0;
        _player2->setGames( 0 );              // p2Games = 0;
        _player1->setSets( 0 );               // p1Sets = 0;
        _player2->setSets( 0 );               // p2Sets = 0;
        _pointLeds.updatePoints();          // UpdatePoints();
        _gameLeds.updateGames();            // UpdateGames();
        _setLeds.updateSets();              // UpdateSets();
        _gameState->setTieBreakOnly( 0 );     // tieBreakOnly = false;
        _gameState->setStarted( 1 ); }}          // gameStart = false; // set to started.
   
void GameModes::mode1() {
    #if defined _WIN32 || defined _WIN64
    std::cout << "inside game mode 1." << std::endl;
    #endif
    _gameState->setNow( GameTimer::gameMillis() );          // now =
    _inputs.readUndoButton();                             // ReadUndoButton();
    if ( _gameState->getUndo() == 1 ) {  // undo button pressed
        #if defined _WIN32 || defined _WIN64
        std::cout << "undo button pressed!" << std::endl;
        #endif
        _gameState->setUndo( 0 );
        #if defined _WIN32 || defined _WIN64
        std::cout << "calling mode1Undo( _history )... " << std::endl;
        #endif                         // set undo = false;
        _undo.mode1Undo( _history );
    }  // Mode1Undo();

    _inputs.readPlayerButtons();  // digital read on player buttons.  sets playerButton if tripped.
    _serveLeds.serveSwitch();     // ServeSwitch(); // if serveSwitch >= 2,
    // serveSwitch = 0; and toggle serve variable

    if ( _gameState->getTieBreak() == 1 ) {
        _mode1TieBreaker.tieBreaker();
    }  // TieBreaker();

    if ( _gameState->getSetTieBreak() == 1 ) {
        _mode1TieBreaker.setTieBreaker();  // SetTieBreaker();
    } else {
        _mode1Functions.mode1ButtonFunction();  // Mode1ButtonFunction();
        _mode1Functions.pointFlash();           // PointFlash(); 
        // nothing happens if point flash is not 1
    }}

void GameModes::mode2() {
    _gameState->setNow( GameTimer::gameMillis() );  // now =
    if ( _gameState->getTieBreakOnly() == 0 ) {
        _gameState->setTieBreak( 1 );  // tieBreak = true;
        _mode1TieBreaker.tieBreakEnable();
        _gameState->setTieBreakOnly( 1 );  // tieBreakOnly = true;
    }
    mode1(); }

void GameModes::mode4() {
    _gameState->setNow( GameTimer::gameMillis() );  // now =
    if ( _gameState->getTieBreakOnly() == 0 ) {
        _gameState->setTieBreak( 1 );  // tieBreak = true;
        _mode1TieBreaker.tieBreakEnable();
        _gameState->setTieBreakOnly( 1 );  // tieBreakOnly = true;
    }
    mode1(); }

void GameModes::testStart() { if ( _gameState->getStarted() == 0 ) {  /* if not started... */ }}

void GameModes::noCode() {
    _player1->setPoints( _player1->getPoints() + 1 );  // p1Points++;
    _pointLeds.updatePoints();                       // UpdatePoints();
    GameTimer::gameDelay( 1000 );
    _player1->setPoints( _player1->getPoints() - 1 );  // p1Points--;
    _pointLeds.updatePoints();                       // UpdatePoints();
    GameTimer::gameDelay( 1000 ); }

void GameModes::setGameMode( int rotaryPosition ) {
    WatchTimer *watchTimer = new WatchTimer();
    BatteryTest batteryTest( _player1, _player2, _pinInterface, &_pointLeds, &_inputs );
    switch ( rotaryPosition ) {
    case 0:
        break;

    case 1:
        #if defined _WIN32 || defined _WIN64
            std::cout << "Game Mode 1" << std::endl;
        #endif
        gameStart();  // sets gameStart to true. resets player and score board.
        mode1();
        break;

    case 4:
        #if defined _WIN32 || defined _WIN64
            std::cout << "Game Mode 2" << std::endl;
            #define TEST_DELAY 150
        #else
            #define TEST_DELAY 500
        #endif
        _player1->setPoints( 100 ); 
        _player2->setPoints( 100 ); 
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setPoints( 0 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setPoints( 1 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setPoints( 2 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setPoints( 3 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setPoints( 4 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setPoints( 100 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };

        _player2->setPoints( 0 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setPoints( 1 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setPoints( 2 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setPoints( 3 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setPoints( 4 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setPoints( 100 );
        _pointLeds.updatePoints();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };

        _gameState->setServe( 1 );
        _serveLeds.updateServeLED();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        
        _gameState->setServe( 0 );
        _serveLeds.updateServeLED();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };

        _pinInterface->pinDigitalWrite( P1_SERVE, LOW);
        _pinInterface->pinDigitalWrite( P2_SERVE, LOW);
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };

        _player1->setSets( 1 );
        _setLeds.updateSets();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setSets( 2 );
        _setLeds.updateSets();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setSets( 0 );
        _setLeds.updateSets();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setSets( 1 );
        _setLeds.updateSets();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setSets( 2 );
        _setLeds.updateSets();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setSets( 0 );
        _setLeds.updateSets();
        _player1->setGames( 99 );
        _player2->setGames( 99 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 0 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 1 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 2 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 3 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 4 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 5 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 6 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player1->setGames( 99 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 99 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 0 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 1 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 2 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 3 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 4 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 5 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 6 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _player2->setGames( 99 );
        _gameLeds.updateGames();
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _pinInterface->pinDigitalWrite( P1_TIEBREAKER, HIGH );
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _pinInterface->pinDigitalWrite( P1_TIEBREAKER, LOW );
        _pinInterface->pinDigitalWrite( P2_TIEBREAKER, HIGH );
        if ( watchTimer->watchInputDelay( TEST_DELAY, &_inputs, WATCH_INTERVAL ) > 0 ) { return; };
        _pinInterface->pinDigitalWrite( P2_TIEBREAKER, LOW);
        break;

    case 2:
        #if defined _WIN32 || defined _WIN64
            std::cout << "Game Mode 3" << std::endl;
        #endif
        gameStart();
        _gameState->setNow( GameTimer::gameMillis() );  // now =
        if ( _gameState->getTieBreakOnly() == 0 ) {
            _gameState->setTieBreak( 1 );  // tieBreak = true;
            _mode1TieBreaker.tieBreakEnable();
            _gameState->setTieBreakOnly( 1 );  // tieBreakOnly = true;
        }
        mode1();
        break;

    case 3:
        batteryTest.execute();  
        break;

    case 5:
        gameStart();
        _player1->setPoints( 5 );
        _pointLeds.updatePoints();
        mode1();
        break;
    }
}