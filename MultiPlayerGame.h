#ifndef PIGDICE_MULTIPLAYERGAME_H
#define PIGDICE_MULTIPLAYERGAME_H
#include <vector>
#include "./PDGameV2.h"

class MultiPlayerGame {
private:
    std::vector<PDGameV2> m_players;
    bool m_gameOver;
public:
    MultiPlayerGame();
    void mpPlayGame();
private:
    void checkForWinner();
    void displayScoreBoard();
};


#endif //PIGDICE_MULTIPLAYERGAME_H
