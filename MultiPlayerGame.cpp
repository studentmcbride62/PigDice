#include <iostream>
#include "MultiPlayerGame.h"

#include <algorithm>

#include "PDGameV2.h"

MultiPlayerGame :: MultiPlayerGame() {
    m_gameOver = false;
    int count = 0;
    std::string tempName;
    std::cout << "How many people are playing? ";
    std::cin >> count;
    std::cin.ignore();
    for (int i = 0; i < count; i++) {
        std::cout << "Enter player " << i + 1 << "'s name: ";
        std::getline(std::cin,tempName);
        auto *ptr = new PDGameV2(tempName);
        m_players.push_back(*ptr);
    }
}

void MultiPlayerGame::displayScoreBoard() {
    std::cout << "\n\n";
    for (int i =0 ; i < m_players.size(); i++) {
       std::cout << m_players.at(i).getPlayerName() << " (Score:" << m_players.at(i).getGameScore() << ") | ";
    }
}

void MultiPlayerGame :: checkForWinner() {
    std::vector<int> over50(m_players.size());
    for (int i = 0; i < m_players.size(); i++) {
        if (m_players.at(i).getGameScore() >= 50) {
            std::cout << m_players.at(i).getGameScore();
            over50.at(i) = m_players.at(i).getGameScore();
            m_gameOver = true;
        }
    }
    if (m_gameOver) {
        auto it = std::max_element(over50.begin(), over50.end());
        long index = std::distance(over50.begin(),it);
        std::cout << "\n\nCongratulations! " << m_players[index].getPlayerName() << " you win with a score of " << m_players[index].getGameScore() << std::endl;
    }
   }

void MultiPlayerGame :: mpPlayGame() {
    m_players[0].displayRules();
    while (!m_gameOver) {
        for (int i = 0; i < m_players.size(); i++) {
            std::cout << "\n\n" << m_players[i].getPlayerName() << " (Score:" << m_players[i].getGameScore() << ") - ";
            m_players.at(i).playGame();
            displayScoreBoard();
        }
        checkForWinner();
    }
}