
#ifndef PIGDICE_STUDENTMCBRIDE62_DIE_H
#define PIGDICE_STUDENTMCBRIDE62_DIE_H

class Die {
private:
    int m_value;
    int m_numOfSides;
public:
    Die();
    void setNumOfSides(int numOfSides);
    int getNumOfSides();
    void setValue();
    int getValue();
};


#endif //PIGDICE_STUDENTMCBRIDE62_DIE_H
