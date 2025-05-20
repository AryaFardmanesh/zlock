#include "io.h"

void readInputFile() {
	#ifdef DEBUG_MODE
	printf(
		"DEBUG: Try to open input file:\n"
		"    Input File Address: %s\n",
		inputFileAddress
	);
	#endif

	// Open the input file
	FILE* fptr = fopen( inputFileAddress, "rb" );
	if ( fptr == NULL ) {
		fprintf( stderr, "Error: Cannot open the specified file.\n" );
		exit( EXIT_FAILURE );
	}

	// Get input file size
	fseek( fptr, 0L, SEEK_END );
	inputFileSize = ftell( fptr );
	rewind( fptr );

	// Set the file buffer
	inputFile = ( char* )malloc( inputFileSize );
	outputFile = ( char* )malloc( inputFileSize );

	// Read the file
	inputFile = fgets( inputFile, inputFileSize, fptr );

	// Close the file
	fclose( fptr );

	#ifdef DEBUG_MODE
	printf(
		"DEBUG: The input file read successfully:\n"
		"    Input File Size: %d\n",
		"    Input File Content: %s\n",
		inputFileSize,
		inputFile
	);
	#endif
}

void writeOutputFile() {
	#ifdef DEBUG_MODE
	printf(
		"DEBUG: Try to write into the output file:\n"
		"    Output File Address: %d\n",
		"    Output File Content: %s\n",
		outputFileAddress,
		outputFile
	);
	#endif

	FILE* fptr = fopen( outputFileAddress, "w" );
	fprintf( fptr, outputFile );
	fclose( fptr );

	#ifdef DEBUG_MODE
	printf( "DEBUG: Written output file successfully." );
	#endif
}

void ioFree() {
	free( inputFile );
	free( outputFile );

	#ifdef DEBUG_MODE
	printf( "DEBUG: IO memories freed successfully." );
	#endif
}
