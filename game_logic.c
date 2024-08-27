#include "game_logic.h"
#include "globals.h"
#include <stdlib.h>

// Set default values for et maximum attempts (10), and create a randomly generated 4-digit answer code
void initialize_config(config *state) {
    state->max_attempts = 10;
    for (int i = 0; i < CODE_LENGTH; i++) {
        state->answer_code[i] = rand() % 10;
    }
}

// Compare the user's guess to the answer code - increment the well and misplaced game piecese accordingly
int compare_guess(game_state *round, int guess_code[], int answer_code[]) {
    round->well_placed_count = 0;
    round->misplaced_count = 0;

    // Compare every digit and it's placement in each array
    for (int i = 0; i < CODE_LENGTH; i++) {
        // Increment well placed count if both arrays have the same int value in the same position
        if (guess_code[i] == answer_code[i]) {
            round->well_placed_count++;
        } else {
            // Increment misplaced count if the same value is encountered in a different position than the answer array
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (guess_code[i] == answer_code[j]) {
                    round->misplaced_count++;
                }
            }
        }
    }
    // If all digits were well placed, return 0, else return 1
    if (round->well_placed_count == CODE_LENGTH) {
        return 0;
    }
    return 1;
}