#ifndef CONVERT_NUMBER_H__
#define CONVERT_NUMBER_H__

#include "hash.h"

#include <stdint.h>

#ifndef SUCCESS
#define SUCCESS 0 ;
#endif

#ifndef FAILURE
#define FAILURE 1 ;
#endif

#define MAX_STRING_SIZE 256

#define TEN       10
#define HUNDRED   100
#define THOUSAND  1000

enum numTypes {
  BILLIONS,
  MILLIONS,
  THOUSANDS,
  HUNDREDS,
  TENS,
  SINGLES
} ;

/**
 * Convert number to string representation.  For example, 128 will yield
 * onehundredtwentyeight
 *
 * @param[in] numToConvert 32-bit integer to convert to string
 * @param[in] lookUpTable Look-up table to use for string conversion
 * @param modulo Used internally for recursion. Should be passed in as 0
 */
char*
convert_number_to_string( uint32_t numToConvert, struct hash* lookUpTable, uint32_t modulo ) ;

#endif

