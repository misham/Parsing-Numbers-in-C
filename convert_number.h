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

enum factors {
  TEN = 10,
  HUNDRED = 100,
  THOUSAND = 1000,
  MILLION = 1000000,
  BILLION = 1000000000
} ;

enum numTypes {
  BILLIONS,
  MILLIONS,
  THOUSANDS,
  HUNDREDS,
  TENS,
  SINGLES
} ;

/**
 * Holds the numerical parts of a number
 */
struct numberRepresentation {
  uint32_t singles ;
  uint32_t tens ;
  uint32_t hundreds ;
  uint32_t thousands ;
  uint32_t millions ;
  uint32_t billions ;
} ;

/**
 * Convert number to string representation.  For example, 128 will yield
 * onehundredtwentyeight
 *
* @return SUCCESS if number was converted, FAILURE otherwise.
 */
char*
convert_number_to_string( uint32_t numToConvert,
                          uint32_t mod,
                          struct hash* lookUpTable ) ;

#endif

