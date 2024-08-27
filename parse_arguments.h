#ifndef PARSE_ARGUMENTS_H 
#define PARSE_ARGUMENTS_H

#include "structs.h"

int parse_args(int argc, char *argv[], config *state);
int parse_code(char char_code[], int int_code[]);
int parse_int(char character, int *code);
int parse_attempts(char *new_max_attempts, int *max_attempts);

#endif