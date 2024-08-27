#include "globals.h"
#include "parse_arguments.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ensure valid # of additional args, then process depending on user's flags; answer code (-c) and/or # of attempts (-t)
int parse_args(int argc, char *argv[], config *state) {
    if (argc == 2) {
        printf("\nError - Not enough arguments specified. Please enter a valid code or attempt value.\n");
    }

    // Initialize index to 1 to skip over executable
    for (int i = 1; i < argc; i++) {
        // parse user input flags, then update answer code and/or max attempts per user input
        if (!(strcmp(argv[i], "-c")) && (i + 1 < argc)) {
            parse_code(argv[i + 1], state->answer_code);
        } else if (!(strcmp(argv[i], "-t")) && (i + 1 < argc)) {
            parse_attempts(argv[i + 1], &state->max_attempts);
        }
    }
    return 0;
}

// Parse user-provided string code and store result in int array
int parse_code(char char_code[], int int_code[]) {
    // Convert each character from code into an integer 
    int result = parse_int(char_code[0], &int_code[0]) ||
                 parse_int(char_code[1], &int_code[1]) ||
                 parse_int(char_code[2], &int_code[2]) ||
                 parse_int(char_code[3], &int_code[3]) || 
                 char_code[CODE_LENGTH] != '\0';
    return result;
}

// Check to see if character is within ASCII range of 0-9, if so, return the character as an integer.
int parse_int(char character, int *code) {
    if (character < '0' || character > '9') {
        return 1;
    }
    *code = character - '0';
    return 0;
}

// Convert string of numbers to integer and return.
int parse_attempts(char *new_max_attempts, int *max_attempts) {
    int result = atoi(new_max_attempts);
    if (result <= 0) {
        return 1;
    }
    *max_attempts = result;
    return 0;
}