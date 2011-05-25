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
 */
char*
convert_number_to_string( uint32_t numToConvert,
    uint32_t modulo,
    struct hash* lookUpTable ) ;

#endif

