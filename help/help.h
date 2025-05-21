#ifndef HELP_H
#define HELP_H

#include "./../version.h"

// ==================== Declaration ====================
void help();
// ==================== Declaration ====================


// ==================== Definition ====================
void help() {
	printf(
		"Encrypt Files With ZLock " ZLOCK_VERSION "\n"
		"Description: ZLock is used to encrypt your files. You can easily encrypt a file without going back.\n"
		"\nUsage Guideline: zlock myfile -o outfile [options]\n"
		"\nOptions:\n"
		"    -p | --password: Takes a secret key for encryption (It should be used to return data).\n"
		"    Example: -p hello_zlock\n"
		"    -h | --hash: Specifies the type of encryption algorithm.\n"
		"    Example: -h xor\n"
		"    -r | --revert: Retrieves hashed data.\n"
		"    Example: -r [-p my_password]\n"
		"\nHashes:\n"
		"    xor: The default algorithm for encryption is to simply xor the data with the key (password).\n"
	);
}
// ==================== Definition ====================

#endif
