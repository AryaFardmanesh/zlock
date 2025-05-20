#ifndef IO_H
#define IO_H

#include <stdio.h>

#include "../parse/parse.h"

size_t inputFileSize = 0;
char* inputFile = NULL;
char* outputFile = NULL;


void readInputFile();
void writeOutputFile();
void ioFree();

#endif
