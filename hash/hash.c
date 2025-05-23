#include "hash.h"

void zlockProcess() {
	if ( revertMode ) {
		if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_XOR ) == 0 ) {
			xorDecrypt();
		}else if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_ASCII_INC ) == 0 ) {
			asciiIncEncrypt();
		}else {
			goto failedToFindHash;
		}
	}else {
		if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_XOR ) == 0 ) {
			xorDecrypt();
		}else if ( strcmp ( hashAlgo, ZLOCK_HASH_ALGO_ASCII_INC ) == 0 ) {
			asciiIncDecrypt();
		}else {
			goto failedToFindHash;
		}
	}

	return;

	failedToFindHash:
		// Not found the hash algo
		memcpy( outputFile, inputFile, inputFileSize );
		return;
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

void asciiIncEncrypt() {
	size_t passLen = strlen( password );
	int passwordVal = 0;

	for ( int i = 0; i < passLen; i++ ) {
		passwordVal += (int)password[ i ];
	}

	for ( size_t i = 0; i < inputFileSize - 1; i++ ) {
		outputFile[ i ] = ( inputFile[ i ] + passwordVal ) % 255;
	}
}

void asciiIncDecrypt() {
	size_t passLen = strlen( password );
	int passwordVal = 0;

	for ( int i = 0; i < passLen; i++ ) {
		passwordVal += (int)password[ i ];
	}

	for ( size_t i = 0; i < inputFileSize; i++ ) {
		ubyte_t ch = inputFile[ i ];

		if ( ( ch - passwordVal ) < 0 ) {
			ch = (ubyte_t)0xff;
		}

		outputFile[ i ] = ( ch - passwordVal ) % 255;
	}
}
