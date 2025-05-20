#include "parse.h"

void parse( int argc, char* argv[] ) {
	if ( argc > 1 && strcmp( argv[ 1 ], "help" ) == 0 ) {
		help();
		exit( EXIT_SUCCESS );
	}

	if ( argc < 4 ) {
		fprintf(
			stderr,
			"Error: No file specified.\n"
			"Use 'zlock help' to learn how to use it.\n"
		);
		exit( EXIT_FAILURE );
	}

	inputFileAddress = argv[ 1 ];
	if ( strcmp( argv[ 2 ], "-o" ) != 0 ) {
		fprintf(
			stderr,
			"Error: The command is wrong.\n"
			"Use 'zlock help' to learn how to use it.\n"
		);
		exit( EXIT_FAILURE );
	}
	outputFileAddress = argv[ 3 ];

	for ( int i = 4; i < argc; i++ ) {
		char* chunk = argv[ i ];

		if ( checkFlag( chunk, "-p", "--password" ) ) {
			exitIfFlagHasNoValue( ++i, argc, "password" );
			password = argv[ i ];
		}else if ( checkFlag( chunk, "-h", "--hash" )  ) {
			exitIfFlagHasNoValue( ++i, argc, "hash" );

			// To uppercase
			char* hash = argv[ i ];
			size_t hashLen = strlen( hash );
			for ( int j = 0; j < hashLen; j++ ) {
				char ch = hash[ j ];
				if ( ch >= 97 && ch <= 122 ) {
					hash[ j ] = ( char )( ch - 32 );
				}
			}

			hashAlgo = hash;
		}else if ( checkFlag( chunk, "-r", "--revert" ) ) {
			revertMode = true;
		}else {
			fprintf(
				stderr,
				"Error: '%s' is invalid flag.\n"
				"Use 'zlock help' to learn how to use it.\n",
				chunk
			);
			exit( EXIT_FAILURE );
		}
	}

	#ifdef DEBUG_MODE
	printf(
		"DEBUG: Call parse function with (ARGC=%d, &ARGV=0x%p):\n"
		"    INPUT_FILE_ADDRESS='%s'\n"
		"    OUTPUT_FILE_ADDRESS='%s'\n"
		"    PASSWORD='%s'\n"
		"    HASH_ALGO='%s'\n"
		"    REVERT_MODE='%d'\n",
		argc,
		argv,
		inputFileAddress,
		outputFileAddress,
		password,
		hashAlgo,
		revertMode
	);
	#endif
}

bool checkFlag( char* value, char* sflag, char* lflag ) {
	return (
		strcmp( value, sflag ) == 0 ||
		strcmp( value, lflag ) == 0
	) ? true : false;
}

void exitIfFlagHasNoValue( int index, int argc, char* name ) {
	if ( index >= argc ) {
		fprintf(
			stderr,
			"Error: The %s command is wrong.\n"
			"Use 'zlock help' to learn how to use it.\n",
			name
		);
		exit( EXIT_FAILURE );
	}
}
