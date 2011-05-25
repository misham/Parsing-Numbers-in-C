#include "convert_number.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// factor of the current mod - 4->40, 2->2000, 80->80000, etc.
uint32_t
get_factor( uint32_t num, uint32_t mod ) {
  return num / mod ;
}

uint32_t
get_starting_modulo( uint32_t num ) {
  if( num > THOUSAND ) {
    return THOUSAND ;
  }
  else if( num > HUNDRED ) {
    return HUNDRED ;
  }
  else {
    return TEN ;
  }
}

char*
convert_number_to_string( uint32_t numToConvert,
                          uint32_t modulo,
                          struct hash* lookUpTable ) {
  uint32_t mod = modulo ;
  if( NULL == lookUpTable ) {
    return NULL ;
  }
  //
  if( 0 == mod ) {
    mod = get_starting_modulo( numToConvert ) ;
    printf( "mod -> %d\n", mod ) ;
  }
  //
  // Check if value is defined in look-up table already
  //
  // This works as a recursion terminating condition since we'll always find single digits
  // as well as anything equal to a whole modulo (10, 100, 1000, etc.).
  //
  // This also let's us handle special case numbers. (Example in English: 11, 12, 13, etc.)
  //
  if( NULL != hash_find_by_key(lookUpTable, numToConvert) ) {
    struct hash* hash_elem = hash_find_by_key( lookUpTable, numToConvert ) ;
    char* return_val = malloc( sizeof(char) * (hash_elem->valLen + 1) ) ;
    strncpy( return_val, hash_elem->val, (hash_elem->valLen + 1) ) ;
    return return_val ;
  }
  else {
    //
		uint32_t cur_num_string_len = 0 ;
		char* cur_num_string = NULL ;
    uint32_t remainder = numToConvert % mod ;
    //
    // Figure out current largest value
    //
		if( numToConvert < 100 ) { // 23 != two ten three
			struct hash* left_over = hash_find_by_key( lookUpTable, (numToConvert - remainder) ) ;
			cur_num_string_len = left_over->valLen ;
			cur_num_string = malloc( sizeof(char) * cur_num_string_len ) ;
			strncpy( cur_num_string, left_over->val, cur_num_string_len ) ;
		}
		else {
			struct hash* factor = hash_find_by_key( lookUpTable, get_factor( (numToConvert-remainder), mod ) ) ;
			struct hash* mod_hash = hash_find_by_key( lookUpTable, mod ) ;
			//
			// Convert largest value into string
			//
			cur_num_string_len = factor->valLen + mod_hash->valLen ;
			cur_num_string = malloc( sizeof(char) * cur_num_string_len ) ;
			strncpy( cur_num_string, factor->val, factor->valLen ) ;
			strncat( cur_num_string, mod_hash->val, mod_hash->valLen ) ;
		}
		//
		// Get next portion of the number
		//
		char* tmp = convert_number_to_string( remainder, (mod/10), lookUpTable ) ;
		//
		// Store all parts
		//
		char* return_val = malloc( sizeof(char) * (cur_num_string_len + strlen(tmp) + 1) ) ;
		strncpy( return_val, cur_num_string, cur_num_string_len ) ;
		strncat( return_val, tmp, strlen(tmp) ) ;
		//
		free( cur_num_string ) ;
		free( tmp ) ;
		//
		return return_val ;
	}
}

