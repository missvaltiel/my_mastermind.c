#include "globals.h"
#include "input_output.h"
#include "parse_arguments.h"
#include <stdio.h> // get_guess & readline for EOF
#include <unistd.h> // read_line read

// Read the input from the user on stdin
int get_guess(int guess_code[]) {

    // Create a buffer for 4 digits + \0 to store user's input
    char buff[CODE_LENGTH + 1]; 

    // Keep asking for input until the user provides a valid guess
    while (1) {
        int read_result = read_line(buff);

        if (read_result == EOF) {
            // Reached EOF - prompt user to re-enter guess
            return EOF;
        } else if (read_result != CODE_LENGTH) {
            // If the chars read was not equal to the code length (4), prompt user to re-enter guess
            printf("Invalid input - guess must be exactly %d digits.(0-9).\n", CODE_LENGTH);
        } else if (parse_code(buff, guess_code) != 0) {
            // Parse the guess code, if the input is valid, break out of loop
            printf("Invalid input - guess must consist of %d digits (0-9).\n", CODE_LENGTH);
        } else {
            // Input valid, break out of loop
            break;
        }
    }
    return 0;
}

// Read a line from stdin from user
int read_line(char line[]) {
    int total_chars_read = 0;
    char character = 0;

    // Keep reading while input is valid and input is not over the code length (4)
    while (total_chars_read <= CODE_LENGTH && read(STDIN_FILENO, &character, 1) == 1) {
        // Stop if we encounter a new line (enter)
        if (character == '\n') {
            break;
        }
        // Store each character in the buffer, and increment +1 each time a character is read
        line[total_chars_read++] = character;
    }
    // Set the end of string with the null terminator
    line[total_chars_read] = '\0';

    // Reached EOF, 
    if (total_chars_read == 0) {
        return EOF;
    }

    // Read and discard from the rest of stdin until a new line, incrementing the # of chars read
    while (character != '\n' && read(STDIN_FILENO, &character, 1) == 1) {
        total_chars_read++;
    }
    // Return the total chars read
    return total_chars_read;
}

// Print the values of a 4 digit integer array, followed by a new line
void print_code(int code[]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        printf("%d", code[i]);
    }
    printf("\n");
}