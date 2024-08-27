#ifndef STRUCTS_H
#define STRUCTS_H

// Struct config for storing the number of maximum attempts and the answer code
typedef struct {
    int max_attempts;
    int answer_code[4];
} config;

// Struct counts for storing # of current attempts & # of well-placed/misplaced pieces
typedef struct {
    int attempt;
    int well_placed_count;
    int misplaced_count;
} game_state;

#endif