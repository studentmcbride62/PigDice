#include "PDGame.h"

#include <iostream>
#include <ostream>

PDGame::PDGame() {
    m_gameOver = false;
    m_gameScore = 0;
    m_myTurn.setParentGame(this); // 7.
    displayRules();
    playGame();
}
int PDGame::getGameScore() const { // 2.
    return m_gameScore;
}
void PDGame::displayRules() {
    std::cout << "Let's Play PIG Dice!\n\n";
    std::cout<<"* See how many turns it takes you to get to 20 points.\n";
    std::cout<<"* Turn ends when you hold or roll a 1.\n";
    std::cout<<"* If you roll a 1, you lose all points for the turn.\n";
    std::cout<<"* If you hold, you bank all points for the turn to the game score.\n";

}
void PDGame::playGame() {
    while (!m_gameOver) {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();
        if (m_gameScore >= 20) {
            m_gameOver = true;
        }
        else {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }
    std::cout << "\n\nYou finished with a final score of ";
    std::cout << m_gameScore;
    std::cout << " in " << m_myTurn.getTurnCount() << " turns! ";
    std::cout << "\nThanks for playing PIG Dice!";

}