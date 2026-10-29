#ifndef PIGDICE_STUDENTMCBRIDE62_TURN_H
#define PIGDICE_STUDENTMCBRIDE62_TURN_H
#include "Die.h"

// 3. add forward declaration of "whole" class (PDGame) so the "part" class (Turn) knows it exists
class PDGame;

class Turn {
private:
    int m_turnCount;
    int m_scoreThisTurn;
    bool m_turnOver;
    char m_choice;
    DIE m_myDie;
    // 4. add a back pointer to the "whole" initialized to null pointer (defensive programming)
    PDGame* m_parentGame = nullptr;
public:
    Turn();
    // 5. add interface for public  setter function to connection “whole” class (PDGame) to “part” class (Turn)
    void setParentGame(PDGame* parentGame);
    void takeTurn();
    int getScoreThisTurn() const;
    void resetTurnOver();
    int getTurnCount();
    void resetScoreThisTurn();
private:
    void roll();
};


#endif //PIGDICE_STUDENTMCBRIDE62_TURN_H
