#include <iostream>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};


void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);


int main() {
    GameState my_game; // instantiate a GameState object
    // display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

void take_turn(GameState &g) {

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
    std::cout << "You finished with a final score of ";
    std::cout << g.game_score;
    std::cout << " in " << g.turn_count << " turns! ";
    std::cout << "\nThanks for playing PIG Dice!";
}

void roll(GameState &g) {

}

void hold(GameState &g) {

}