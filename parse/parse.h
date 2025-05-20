#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../hash/hash.h"
#include "../help/help.h"

char* inputFileAddress = NULL;
char* outputFileAddress = NULL;
char* password = ZLOCK_DEFAULT_PASSWORD;
char* hashAlgo = ZLOCK_DEFAULT_HASH_ALGO;
bool revertMode = false;


void parse();
bool checkFlag( char*, char*, char* );
void exitIfFlagHasNoValue( int, int, char* );

#endif
