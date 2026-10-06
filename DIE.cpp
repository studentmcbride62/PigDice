#include <random>
#include "DIE.h"

Die::Die() {  // default constructor
    m_numOfSides = 6;
    setValue();
}

void Die::setNumOfSides(int numOfSides) {
    switch (numOfSides) {
        case 4:
            m_numOfSides = 4;
            break;
        case 6:
            m_numOfSides = 6;
            break;
        case 8:
            m_numOfSides = 8;
            break;
        default:
            m_numOfSides = 6;
    }

}
int Die::getNumOfSides() {
    return m_numOfSides;
}

void Die::setValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,m_numOfSides);
    m_value = dis(gen);
}

int Die::getValue() {
    // rules for accessing the data
    return m_value;
}