#ifndef PIGDICE_PDGAMEV2_H
#define PIGDICE_PDGAMEV2_H
#include <string>
#include "PDGame.h"


class PDGameV2:public PDGame {
private:
    std::string m_playerName;
public:
    PDGameV2(std::string &playersName);
    /*virtual ~PDGameV2() {
        // destruct PDGameV2 object
    }*/
    std::string getPlayerName() const;
    static void displayRules();
    void playGame() override;
};


#endif //PIGDICE_PDGAMEV2_H
