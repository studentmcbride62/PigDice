#include <random>
#include "DIE.h"

DIE::DIE() {  // default constructor
    m_dieValue=0;
}

void DIE::rollDie() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,6);
    m_dieValue = dis(gen);
}

int DIE::getDieValue() const {
    // rules for accessing the data
    return m_dieValue;
}