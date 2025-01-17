#include <iostream>

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void display_rules();
void hold(GameState & my_game);
void roll(GameState & my_game);
void take_turn(GameState & my_game);
void play_game(GameState & my_game);



int main() {

    GameState my_game;

    display_rules();
    play_game(my_game);
    return 0;
}

void display_rules() {
    std::cout << "Let's Play PIG Dice!";
    std::cout << "\n\n* See how many turns it takes you to get to 20.";
    std::cout << "\n* Turn ends when you hold or roll a 1.";
    std::cout << "\n* If you roll a 1, you lose all points for the turn.";
    std::cout << "\n* If you hold, you save all points for the turn.";
}

void play_game(GameState & my_game) {
    while(!my_game.game_over) {
        take_turn(my_game);
    }
    std::cout << "\n\nYou finished with a final score of 20 or more in " << my_game.turn_count << " turns!";
}

void take_turn(GameState & my_game) {
    my_game.turn_count++;
    std::cout << "\n\nTURN " << my_game.turn_count;
    while(!my_game.turn_over) {
        char choice;
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> choice;
        if(choice == 'r') {
            roll(my_game);
        }
        else if(choice == 'h') {
            hold(my_game);
        }
        else {
            std::cout << "Invalid choice! Try again.";
        }
    }
    std::cout << "Score for turn:" << my_game.score_this_turn;
    std::cout << "\nTotal score:" << my_game.game_score;
    my_game.turn_over = false;
    my_game.score_this_turn = 0;
}

void roll(GameState & my_game) {
    srand(time(NULL));
    int die_value = rand() % 6 +1;
    std::cout << "Die: " << die_value;
    if (die_value == 1) {
        my_game.score_this_turn = 0;
        my_game.turn_over = true;
        std::cout << "\nTurn over. No score.\n";
    }
    else {
        my_game.score_this_turn += die_value;
    }
}

void hold(GameState & my_game) {
    my_game.turn_over = true;
    my_game.game_score += my_game.score_this_turn;
    if (my_game.game_score >= 20) {
        my_game.game_over = true;
    }
}
