#include <iostream>
#include "PDGameV2.h"

PDGameV2::PDGameV2(std::string &playerName){
    static int index=1;
    if (playerName != "") {
        m_playerName = playerName;
    }
    else {
        m_playerName = "Anonymous Player " + std::to_string(index);
        index++;
    }
}

std::string PDGameV2::getPlayerName() const {
    return m_playerName;
}

void PDGameV2::displayRules() {
    std::cout << "\nLet's Play PIG Dice!\n";
    std::cout << "\n* See which player will reach 50 points in the fewest turns.";
    std::cout << "\n* Turn ends when you hold or roll a 1";
    std::cout << "\n* If you roll a 1, you lose all points for the turn.";
    std::cout << "\n* If you hold, you save all points for the turn.";
}

void PDGameV2::playGame() {
    m_myTurn.takeTurn();
    m_gameScore += m_myTurn.getScoreThisTurn();
    if (m_gameScore >= 50) {
        m_gameOver = true;
    }
    else {
        m_myTurn.resetTurnOver();
        m_myTurn.resetScoreThisTurn();
    }
}