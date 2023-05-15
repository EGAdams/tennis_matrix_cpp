#include "ScoreBoard.h"
#include "Arduino.h"

ScoreBoard::ScoreBoard(Player* player1,
                       Player* player2,
                       WebLiquidCrystal* lcdDisplay)
    : _player1(player1), _player2(player2), _lcd(lcdDisplay) {
  _lcd->init();
  _lcd->backlight();
  // _lcd->setCursor(3, 0);
  // _lcd->print("Hello, earth. ");
  // _lcd->setCursor(2, 1);
  // _lcd->print("Ywrobot Arduino!");
  // _lcd->setCursor(1, 2);
  // _lcd->print("Arduino LCM IIC");
}
ScoreBoard::~ScoreBoard() { /* Serial.println( "ScoreBoard destructor called.");
                             */
}

void ScoreBoard::update() {
  // _lcd->setCursor(1, 0);
  // _lcd->print("PLayer1   Player2");
  // _lcd->setCursor(1, 1);
  // _lcd->print("Points:" + std::to_string(_player1->getPoints()) +
  //             "  Points:" + std::to_string(_player2->getPoints()));
  // _lcd->setCursor(1, 2);
  // _lcd->print("Games :" + std::to_string(_player1->getGames()) +
  //             "  Games :" + std::to_string(_player2->getGames()));
  // _lcd->setCursor(1, 3);
  // _lcd->print("Sets  :" + std::to_string(_player1->getSets()) +
  //             "  Sets  :" + std::to_string(_player2->getSets()));
}
