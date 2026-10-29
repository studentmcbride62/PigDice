#ifndef PIGDICE_STUDENTMCBRIDE62_DIE_H
#define PIGDICE_STUDENTMCBRIDE62_DIE_H

class Die {
private:
    int m_dieValue;

public:
    Die();

    void rollDie();

    int getDieValue() const;
};


#endif //PIGDICE_STUDENTMCBRIDE62_DIE_H
