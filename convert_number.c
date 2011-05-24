#include "convert_number.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int
convert_number_to_string( uint32_t numToConvert,
                          char* lookUpTable[],
                          uint32_t lookUpTableLen,
                          char** convertedNumber,
                          uint32_t* convertedNumberLen ) {
	if( 0 == lookUpTableLen || NULL == lookUpTable ) {
		return FAILURE ;
	}
  //
  *convertedNumber = malloc( sizeof(char) * MAX_STRING_SIZE ) ;
  *convertedNumberLen = MAX_STRING_SIZE ;
  //
  break_down_number( numToConvert, 0,
                     *convertedNumber,
                     convertedNumberLen ) ;
	//
	return SUCCESS ;
}

int
break_down_number( uint32_t number,
                   uint32_t position,
                   char* lookUpTable[],
                   uint32_t lookUpTableLen,
                   char* convertedNumber,
                   uint32_t* convertedNumberLen ) {
  uint32_t mod = 0 ;
  //
  if( NULL == convertedNumber || 0 == convertedNumberLen ||
      NULL == lookUpTable || 0 == lookUpTableLen ) {
    return FAILURE ;
  }
  //
  if( 0 == position ) {
    mod = BILLION ;
  }
  //
  // Check if number exists in look-up table.  If so, we're done
  //

  //
  return SUCCESS ;
}

