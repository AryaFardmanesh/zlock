#include "zlock.h"

int main( int argc, char* argv[] ) {
	#ifdef DEBUG_MODE
	printf( "DEBUG: Program started.\n" );
	#endif

	parse( argc, argv );
	readInputFile();
	zlockProcess();
	writeOutputFile();

	out:
		ioFree();

		#ifdef DEBUG_MODE
		printf( "DEBUG: Program finished.\n" );
		#endif

		exit( EXIT_SUCCESS );
}
