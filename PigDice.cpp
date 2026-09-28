#include <iostream>
#include <random>


// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

class Die {
private:
    int m_value;
    int m_numOfSides;
public:
    Die() {  // default constructor
        m_numOfSides = 6;
        setValue();
    }

    void setNumOfSides(int numOfSides) {
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
    int getNumOfSides() {
        return m_numOfSides;
    }

    void setValue() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1,m_numOfSides);
        m_value = dis(gen);
    }

    int getValue() {
        // rules for accessing the data
        return m_value;
    }
};

// example diff

void display_rules();
void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);


int main() {
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

void display_rules() {
    std::cout << "Let's Play PIG Dice!\n\n";
    std::cout<<"* See how many turns it takes you to get to 20 points.\n";
    std::cout<<"* Turn ends when you hold or roll a 1.\n";
    std::cout<<"* If you roll a 1, you lose all points for the turn.\n";
    std::cout<<"* If you hold, you bank all points for the turn to the game score.\n";
}

void play_game(GameState &g) {
    while (!g.game_over) {
        take_turn(g);
        g.game_score += g.score_this_turn;
        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }
    std::cout << "\n\nYou finished with a final score of ";
    std::cout << g.game_score;
    std::cout << " in " << g.turn_count << " turns! ";
    std::cout << "\nThanks for playing PIG Dice!";
}

void take_turn(GameState &g) {
    g.turn_count++;
    std::cout << "\n\nTURN " << g.turn_count;
    std::cout << " - Game Score: " << g.game_score;
    while (!g.turn_over) {
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> g.choice;
        if (g.choice == 'r') {
            roll(g);
        }
        else if (g.choice == 'h') {
            hold(g);
        }
        else {
            std::cout << "Invalid choice!";
        }
    }
    std::cout << "Score Banked This Turn: " << g.score_this_turn;
}

void roll(GameState &g) {
    /*srand(time(NULL));
    int die = rand() % 6 + 1;*/
    Die myDie;  // calls the default constructor
    //myDie.setValue();  // calling the public function to roll the die
    std::cout << "Die: " << myDie.getValue();
    if (myDie.getValue() == 1) {
        std::cout << "\nTurn over. No score.\n";
        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn+=myDie.getValue();
        std::cout << " - Running score this turn: " << g.score_this_turn;
    }
}

void hold(GameState &g) {
    g.turn_over = true;
}