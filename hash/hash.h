#ifndef HASH_H
#define HASH_H

#include "../parse/parse.h"
#include "../io/io.h"

#define ZLOCK_HASH_ALGO_XOR "XOR"

#define ZLOCK_DEFAULT_PASSWORD "ZLOCK"
#define ZLOCK_DEFAULT_HASH_ALGO ZLOCK_HASH_ALGO_XOR


void zlockProcess();

void xorEncrypt();
void xorDecrypt();

#endif
