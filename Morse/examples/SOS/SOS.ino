#include <DIGI_V6_15.h>
#include <GAME_LEDs.h>
#include <GAME_MODES.h>
#include <GameObject.h>
#include <GameState.h>
#include <GameTimer.h>
#include <INPUTS.h>
#include <MODE_1_FUNCTIONS.h>
#include <MODE_2_FUNCTIONS.h>
#include <MODE_1_SCORE.h>
#include <MODE_1_TIEBREAKER.h>
#include <Morse.h>
#include <PinInterface.h>
#include <PinState.h>
#include <Player.h>
#include <POINT_LEDs.h>
#include <RESET.h>
#include <ScoreBoard.h>
#include <SERVE_LEDs.h>
#include <SET_LEDs.h>
#include <UNDO.h>
#include <History.h>
#include <Logger.h>

void setup() {
    pinMode( PLAYER_BUTTONS, INPUT );
    pinMode( ROTARY, INPUT);
    pinMode( UNDO, INPUT );
    pinMode( RESET, INPUT ); 

    pinMode( P1_POINTS_LED1, OUTPUT );
    pinMode( P1_POINTS_LED2, OUTPUT );
    pinMode( P1_POINTS_LED3, OUTPUT );
    pinMode( P1_POINTS_LED4, OUTPUT ); 

    pinMode( P2_POINTS_LED1, OUTPUT );
    pinMode( P2_POINTS_LED2, OUTPUT );
    pinMode( P2_POINTS_LED3, OUTPUT );
    pinMode( P2_POINTS_LED4, OUTPUT ); 

    pinMode( P1_SERVE, OUTPUT );
    pinMode( P2_SERVE, OUTPUT ); 

    pinMode( P1_GAMES_LED0, OUTPUT );
    pinMode( P1_GAMES_LED1, OUTPUT );
    pinMode( P1_GAMES_LED2, OUTPUT );
    pinMode( P1_GAMES_LED3, OUTPUT );
    pinMode( P1_GAMES_LED4, OUTPUT );
    pinMode( P1_GAMES_LED5, OUTPUT );
    pinMode( P1_GAMES_LED6, OUTPUT );
    pinMode( P1_TIEBREAKER, OUTPUT ); 

    pinMode( P2_GAMES_LED0, OUTPUT );
    pinMode( P2_GAMES_LED1, OUTPUT );
    pinMode( P2_GAMES_LED2, OUTPUT );
    pinMode( P2_GAMES_LED3, OUTPUT );
    pinMode( P2_GAMES_LED4, OUTPUT );
    pinMode( P2_GAMES_LED5, OUTPUT );
    pinMode( P2_GAMES_LED6, OUTPUT );
    pinMode( P2_TIEBREAKER, OUTPUT ); 

    pinMode( P1_SETS_LED1, OUTPUT );
    pinMode( P1_SETS_LED2, OUTPUT ); 

    pinMode( P2_SETS_LED1, OUTPUT );
    pinMode( P2_SETS_LED2, OUTPUT ); 

    Serial.begin( 9600 ); }

GameObject gameObject;

void loop() { gameObject.loopGame(); }

/*
 *  PCB #2 T.v44
 * 
 *  Tuesday, March 22, 2023 2:45 PM
 *  Version 41
 *  Modified battery test blink delay to 1 second.
 * 
 *  https://americansjewelry.com/scoreprolibraries/tennis_libraries/PCB_2_T_v41__changed_battery_test_delay_to_1s.zip
 * 
 */


/*  
    ////////////////// Start Change Log /////////////////////////////
    Tuesday, March 22, 2023 2:45 PM
    Version 41
    * Modified battery test blink delay to 1 second.

    Monday, March 20, 2023 4:00 PM
    Version 40
    * Slow down tie break blink.
    * Slow down battery test blink.
    * Added blink loop to setTieBreaker() method.

    Monday, March 20, 2023 12:00 PM
    Version 39
    * Add watch timer to tie breaker to stop when the rotary switch changes.
    * Increased the amount of times that the battery flash test is repeated to make the total delay 30 seconds.
    
    Saturday, March 18 2023 6:15 PM
    Version 38
    * Implemented battery test.

    Saturday, March 18 2023 5:45 PM
    Version 37
    * Implemented MatchWinSequence::run() method.

    Friday March 17, 2023 4:15 PM
    * Change the Set win count from 3 to 5 for regular game and tie break.

    Thursday March 16, copied version 27 in.  Added defines so that the MatchWinSequence
    class will compile.  The MatchWinSequence class is not used in this version of the release.
    It won't be used until we can get a good run.

    ONLY changed and verified TB blink.
    

    Wednesday March 15, 2023 9:00 PM
    * Both Green and Red game lamps now go to 6 before tie break blink.
    * The losing player's score no longer jumps to 6.
    * Reduced match win flash delay to 200ms from 1 second.
    * Swapped Rotary positions 3 and 4.
    
    Tuesday March 14, 2023 11:15 AM
    In the Mode1WinSequences, method p1TBSetWinSequence() {  // for entering set t/b
    * Force both player 1 and player to have 6 games.  
    * Game Lamps #6 for player 1 and player 2 will then go off after the tie break LED blink.


    Monday March 13, 2023 7:30 PM
    * Notes for modifications on March 13 ( day after time change weekend )
    * Set #define GAME_FLASH_DELAY 200 for real world and 1000 for simulator.
    * 200ms is too fast for real world.
    * gameState->getGameFlashDelay()  is connected to this constant in the
      GameWinSequence::run() method.

    /////////////////// End Change Log //////////////////////////////
*/
