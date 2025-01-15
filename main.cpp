#include <iostream>

void display_rules();
void hold(bool &turn_over, int &game_score, int &score_this_turn, bool &game_over);
void roll(int &score_this_turn, bool &turn_over);
void take_turn(int &turn_count, bool &turn_over, int &game_score, int &score_this_turn, bool &game_over);
void play_game(bool &game_over, int &turn_count, int &score_this_turn, int &game_score, bool &turn_over);

int main() {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;

    display_rules();
    play_game(game_over, turn_count, score_this_turn, game_score, turn_over);
    return 0;
}

void display_rules() {
    std::cout << "Let's Play PIG Dice!";
    std::cout << "\n\n* See how many turns it takes you to get to 20.";
    std::cout << "\n* Turn ends when you hold or roll a 1.";
    std::cout << "\n* If you roll a 1, you lose all points for the turn.";
    std::cout << "\n* If you hold, you save all points for the turn.";
}

void play_game(bool &game_over, int &turn_count, int &score_this_turn, int &game_score, bool &turn_over) {
    while(!game_over) {
        take_turn(turn_count, turn_over, game_score, score_this_turn, game_over);
    }
    std::cout << "\n\nYou finished with a final score of 20 or more in " << turn_count << " turns!";
}

void take_turn(int &turn_count, bool &turn_over, int &game_score, int &score_this_turn, bool &game_over) {
    turn_count++;
    std::cout << "\n\nTURN " << turn_count;
    while(!turn_over) {
        char choice;
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> choice;
        if(choice == 'r') {
            roll(score_this_turn, turn_over);
        }
        else if(choice == 'h') {
            hold(turn_over, game_score, score_this_turn, game_over);
        }
        else {
            std::cout << "Invalid choice! Try again.";
        }
    }
    std::cout << "Score for turn:" << score_this_turn;
    std::cout << "\nTotal score:" << game_score;
    turn_over = false;
    score_this_turn = 0;
}

void roll(int &score_this_turn, bool &turn_over) {
    srand(time(NULL));
    int die_value = rand() % 6 +1;
    std::cout << "Die: " << die_value;
    if (die_value == 1) {
        score_this_turn = 0;
        turn_over = true;
        std::cout << "\nTurn over. No score.\n";
    }
    else {
        score_this_turn += die_value;
    }
}

void hold(bool &turn_over, int &game_score, int &score_this_turn, bool &game_over) {
    turn_over = true;
    game_score += score_this_turn;
    if (game_score >= 20) {
        game_over = true;
    }
}
