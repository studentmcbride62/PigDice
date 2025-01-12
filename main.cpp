#include <iostream>

int main() {
    char choice;
    int turn_count = 0;
    int die_value = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;

    std::cout << "Let's Play PIG Dice!";
    std::cout << "\n\n* See how many turns it takes you to get to 20.";
    std::cout << "\n* Turn ends when you hold or roll a 1.";
    std::cout << "* If you roll a 1, you lose all points for the turn.";
    std::cout << "* If you hold, you save all points for the turn.";

    while(!game_over) {
        turn_count++;
        std::cout << "\n\nTURN " << turn_count;
        while(!turn_over) {
            std::cout << "\nroll or hold? (r/h): ";
            std::cin >> choice;
            if(choice == 'r') {
                srand(time(NULL));
                die_value = rand() % 6 +1;
                std::cout << "Die: " << die_value;
                if (die_value == 1) {
                    score_this_turn = 0;
                    turn_over = true;
                    std::cout << "\nTurn over. No score.";
                }
                else {
                    score_this_turn += die_value;
                }
            }
            else if(choice == 'h') {
                turn_over = true;
                game_score += score_this_turn;
                if (game_score >= 20) {
                    game_over = true;
                }
            }
            else {
                std::cout << "\nInvalid choice! Try again.";
            }
        }
        std::cout << "\nScore for turn:" << score_this_turn;
        std::cout << "\nTotal score:" << game_score;
        turn_over = false;
        score_this_turn = 0;
    }
    std::cout << "\n\nYou finished with a final score of 20 or more in " << turn_count << " turns!";
    return 0;
}
