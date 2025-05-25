#include "hash.h"

void zlockProcess() {
	if ( revertMode ) {
		if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_XOR ) == 0 ) {
			xorDecrypt();
		}else {
			goto failedToFindHash;
		}
	}else {
		if ( strcmp( hashAlgo, ZLOCK_HASH_ALGO_XOR ) == 0 ) {
			xorDecrypt();
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

	for ( size_t i = 0; i < inputFileSize - 1; i++ ) {
		outputFile[ i ] = ( inputFile[ i ] ^ password[ i % passLen ] );
	}
}

void xorDecrypt() {
	xorEncrypt();
}

