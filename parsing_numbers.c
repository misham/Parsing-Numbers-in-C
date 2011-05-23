#include "convert_number.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void
set_lookup_table_value( char** cell, char* value, uint32_t valueLen ) {
  uint32_t c_string_value_len = valueLen + 1 ;
	char* table_cell = malloc( sizeof(char) * c_string_value_len ) ;
	strncpy( table_cell, value, c_string_value_len ) ;
	table_cell[valueLen] = '\0' ;
  //
  *cell = table_cell ;
}

int
main( int argc, char* argv[] ) {
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
  {
    int i = 0 ;
    for( i = 0; i < 100; ++i ) {
      if( NULL != (look_up_table[i]) ) {
        printf( "%d => %s\n", i, (look_up_table[i]) ) ;
      }
    }
  }
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

