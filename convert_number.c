#include "convert_number.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// :TODO: Deal with 10,000 100,000,000 etc.
uint32_t
get_modulo( uint32_t mod ) {
  return mod / 10 ;
}

// factor of the current mod - 4->40, 2->2000, 8->30000, etc.
uint32_t
get_factor( uint32_t num, uint32_t mod ) {
  return num / mod ;
}

char*
convert_number_to_string( uint32_t numToConvert,
                          uint32_t mod,
                          struct hash* lookUpTable ) {
  if( NULL == lookUpTable ) {
    return NULL ;
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
    uint32_t remainder = numToConvert % mod ;
    //
    // Figure out current largest value
    //
    uint32_t left_over = numToConvert - remainder ;
    struct hash* factor = hash_find_by_key( lookUpTable, get_factor( left_over, mod ) ) ;
    struct hash* mod_hash = hash_find_by_key( lookUpTable, mod ) ;
    //
    // Convert largest value into string
    //
    uint32_t cur_num_string_len = factor->valLen + mod_hash->valLen ;
    char* cur_num_string = malloc( sizeof(char) * cur_num_string_len ) ;
    strncpy( cur_num_string, factor->val, factor->valLen ) ;
    strncat( cur_num_string, mod_hash->val, mod_hash->valLen ) ;
    //
    // Get next portion of the number
    //
    uint32_t new_mod = get_modulo( mod ) ;
    char* tmp = convert_number_to_string( remainder, new_mod, lookUpTable ) ;
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

