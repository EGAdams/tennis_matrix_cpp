#ifndef DIGI_V6_15_H
#define DIGI_V6_15_H
#include "Arduino.h"

//  Written by Chris Bean for Teensy 4.1 only
//  re-written in C++ by EG in June 2022

#define GAME_FLASH_DELAY         1000
#define FLASH_DELAY              1000
#define BUTTON_DELAY             300
#define WIN_DELAY                1000        
#define WATCH_INTERVAL           250
#define UPDATE_DISPLAY_DELAY     50
#define LOOP_MATCH_LAMP_WIN      5
#define NUMBER_OF_GAME_LAMPS     7
#define LOOP_GAME_LAMP_WIN       5
#define TIE_PULSE_COUNT          5
#define SET_WIN_PULSE_COUNT      5
#define TIE_BREAK_BLINK_DELAY    750
#define TIE_BREAK_WATCH_INTERVAL 50
#define BATTERY_TEST_BLINK_DELAY 1000
      

// #define INPUT 0 // not in windows.. ouch!!
// #define OUTPUT 0
#define LOW 0
#define HIGH 1
#define BLINK 2

#if defined _WIN32 
///////////////////////////////////////  START WINDOWS SIMULATOR //////////////////////////////////
    #define SIMULATION 1
    #define PLAYER_BUTTONS 202
    #define ROTARY 150
    #define LOG_FILE_PATH          "C:\\Users\\EG\\Desktop\\2022\\june\\4th_week\\test.txt"
    #define PIN_FILE_PATH          "C:\\Users\\EG\\Desktop\\2022\\june\\2nd_week\\tennis_cpp\\pin_data\\"
    #define GAME_STATE_UPDATE_PATH "C:\\Users\\EG\\Desktop\\2022\\june\\2nd_week\\tennis_cpp\\game_state_data\\"
    #define MATCH_WIN_FLASH_DELAY  200
    #define BATTERY_TEST_DELAY      500
    #define BATTERY_TEST_FLASH_COUNT 5
    #include <iostream>
//////////////////////////////////// END WINDOWS SIMULATION /////////////////////////////////////
#else
///////////////////////////////////   START ARDUINO /////////////////////////////////////////////
    #define SIMULATION 0
    #define PLAYER_BUTTONS A10 // A14 // A10  // A2  //  Changed from A2 to A10. A2 is for PCB #1, A10 is for PCB #2.
    #define ROTARY A12 // A15 changed to A12
    #define LOG_FILE_PATH "unkown file system"
    #define MATCH_WIN_FLASH_DELAY    200
    #define BATTERY_TEST_DELAY       30000
    #define BATTERY_TEST_FLASH_COUNT 15 // ( 2 * BATTERY_TEST_BLINK_DELAY * BATTERY_TEST_FLASH_COUNT = 2 * 1,000ms + 15,000ms = 30s)
////////////////////////////////////  END ARDUINO /////////////////////////////////////////////////
#endif


#define UNDO  39 
#define RESET 38

#define P1_POINTS_LED1 22
#define P1_POINTS_LED2 23
#define P1_POINTS_LED3 0
#define P1_POINTS_LED4 1
#define P1_SERVE 19
#define P1_GAMES_LED0 31
#define P1_GAMES_LED1 18
#define P1_GAMES_LED2 15
#define P1_GAMES_LED3 14
#define P1_GAMES_LED4 41
#define P1_GAMES_LED5 37
#define P1_GAMES_LED6 36
#define P1_TIEBREAKER 33
#define P1_SETS_LED1 29
#define P1_SETS_LED2 30
#define P2_POINTS_LED1 21
#define P2_POINTS_LED2 20
#define P2_POINTS_LED3 3
#define P2_POINTS_LED4 2
#define P2_SERVE 4
#define P2_GAMES_LED0 32
#define P2_GAMES_LED1 5
#define P2_GAMES_LED2 6
#define P2_GAMES_LED3 7
#define P2_GAMES_LED4 8
#define P2_GAMES_LED5 9
#define P2_GAMES_LED6 10
#define P2_TIEBREAKER 11
#define P2_SETS_LED1 28
#define P2_SETS_LED2 12
#endif
