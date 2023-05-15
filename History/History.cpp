#include "History.h"

History::History() {
    _logger = new Logger( "History" );
}
History::~History() {}

void History::push( GameState state ) {
    _history.push( state );
}

int History::size() {
    return _history.size();
}

GameState History::pop() {
    _logger->logUpdate( "inside history pop...", __FUNCTION__ );
    GameState lastGameState = _history.top();
    _history.pop();
    return lastGameState;
}
