#include "hash.h"

void zlockProcess() {
	if ( revertMode ) {
		if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_XOR ) == 0 ) {
			xorDecrypt();
		}
	}else {
		if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_XOR ) == 0 ) {
			xorEncrypt();
		}
	}
}

void xorEncrypt() {
	size_t passLen = strlen( password );

	for ( size_t i = 0; i < inputFileSize; i++ ) {
		outputFile[ i ] = ( inputFile[ i ] ^ password[ i % passLen ] );
	}
}

void xorDecrypt() {
	xorEncrypt();
}
