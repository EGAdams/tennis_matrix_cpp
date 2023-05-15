/*
 *
 */
#include "GameState.h"
#include "DIGI_V6_15.h"
#include "Logger.h"

class SubjectManager {
public:
    SubjectManager();
    ~SubjectManager();
    void gameStateUpdate( GameState* gameState, Player* player1, Player* player2 );
private:
    Logger* _logger;
};
