#ifndef PIGDICE_STUDENTMCBRIDE62_PDGAME_H
#define PIGDICE_STUDENTMCBRIDE62_PDGAME_H
#include "Turn.h"

class PDGame {
private:
    Turn m_myTurn;
    bool m_gameOver;
    int m_gameScore;
public:
    PDGame();
    // 1. add interface for public getter method to return private m_gameScore from “whole”
    int getGameScore() const;
private:
    void displayRules();
    void playGame();
};


#endif //PIGDICE_STUDENTMCBRIDE62_PDGAME_H
