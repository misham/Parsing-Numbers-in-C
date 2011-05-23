#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char*
convert_number_to_string( uint32_t numToConvert, char** lookUpTable, uint32_t lookUpTableLen ) {
	if( 0 == lookUpTableLen || NULL == lookUpTable ) {
		return NULL ;
	}
	else if( 0 == numToConvert ) {
		char* tmp = malloc( sizeof(char) * (strlen("zero")+1) ) ;
		return tmp ;
	}
	//
	char* return_val = malloc( sizeof(char) * 256 ) ;
	snprintf( return_val, 256, "%d", numToConvert ) ;
	return return_val ;
}

char*
break_down_number( uint32_t number, uint32_t mod ) {
	char* return_val = NULL ;
	if( 0 == number ) {
		return NULL ;
	}
	//
	return_val = NULL ;
}

