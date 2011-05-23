#include "convert_number.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void
set_lookup_table_value( char** cell, char* value, uint32_t valueLen ) {
	*cell = malloc( sizeof(char) * valueLen ) ;
	strncpy( *cell, value, valueLen ) ;
	*cell[valueLen] = '\n' ;
}

int main( int argc, char* argv[] ) {
	uint32_t number_to_convert = 0 ;
	char** look_up_table = NULL ; // Array of char*'s
	char* result = NULL ;
	//
  number_to_convert = 7 ;
	//
	look_up_table = malloc( sizeof(char*) * 100 ) ;
	set_lookup_table_value( &(look_up_table[7]), "seven", strlen("seven") ) ;
	set_lookup_table_value( &(look_up_table[20]), "twenty", strlen("twenty") ) ;
	set_lookup_table_value( &(look_up_table[100]), "hundred", strlen("hundred") ) ;
	//
	result = convert_number_to_string( number_to_convert, look_up_table, 100 ) ;
	printf( "Result: %s\n", result ) ;
	//
	// Clean Up
	//
	free( look_up_table ) ;
	free( result ) ;
	//
	return EXIT_SUCCESS ;
}

