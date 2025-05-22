#ifndef IO_H
#define IO_H

#include <stdio.h>

#include "../parse/parse.h"

typedef unsigned char ubyte_t;

size_t inputFileSize = 0;
ubyte_t* inputFile = NULL;
ubyte_t* outputFile = NULL;


void readInputFile();
void writeOutputFile();
void ioFree();

#endif
