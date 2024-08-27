#include "game_logic.h"
#include "globals.h" // function headers, structs, const
#include "input_output.h"
#include "parse_arguments.h"
#include <stdio.h> // get_guess & readline for EOF & printf
#include <time.h> // time in mastermind 
#include <stdlib.h> // srand mastermind, rand initiailize config

// Length of the answer code & player's guess
const int CODE_LENGTH = 4;  

int mastermind(int argc, char *argv[]);

// Program starts at main
int main(int argc, char *argv[]) {
    // if mastermind function returned an error, end program with error by returning 1
    if (mastermind(argc, argv) != 0) {
        return 1;
    }
    return 0;
}

int mastermind(int argc, char *argv[]) {
    // Seed the random number generator with the current time.
    srand(time(NULL)); 

    // declare and initialize a config
    config state;
    initialize_config(&state);

    // If user provided more arguments than just the executable from stdin, parse the additional arguments
    if (argc > 1) {
        if (parse_args(argc, argv, &state) == -1) {
            return 1;
        }
    }

    // Initialize a struct of game_state, called round with all zero values
    game_state round = {0};
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    // While the user has not reached the set maximum attempts, allow them to input a new 4 digit guess
    while (round.attempt < state.max_attempts) {
        printf("---\nRound %d\n", round.attempt++);

        int new_guess[4] = {0};
        // Get the new guess for the code from the user on stdin
        if (get_guess(new_guess) == -1) {
            return 1;
        }

        // Compare the new guess code to the stored answer code - if compare_guess returns 0, the guess was correct & game ends
        if (!compare_guess(&round, new_guess, state.answer_code)) {
            printf("Congratz! You did it!\n");
            return 0;
        }
        // Print the counts for each round
        printf("Well placed pieces: %d\n", round.well_placed_count);
        printf("Misplaced pieces: %d\n", round.misplaced_count);
    }

    // If they exceded the number of attempts allowed, print lose message, the answer, and end game
    printf("You lose, the code was ");
    print_code(state.answer_code);
    return 0;
}