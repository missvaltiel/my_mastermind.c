#ifndef GAME_LOGIC_H 
#define GAME_LOGIC_H

#include "structs.h"

void initialize_config(config *state);
int compare_guess(game_state *round, int guess_code[], int answer_code[]);

#endif