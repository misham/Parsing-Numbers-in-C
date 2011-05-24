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
 * @param[in] numToConvert Number to convert to string
 * @param[in] lookUpTable Look up table containing strings
 * @param[in] lookUpTableLen Length of the lookUpTable
 * @param[out] convertedNumber String containing converted number
 * @param[out] convertedNumberLen Length of the converted number string
 *
 * @note
 * The format of the look-up table is an array with digits and their
 * numerical values.  Example:
 *
 * [0] => "zero"
 * [1] => "one"
 * ...
 * [10] => "ten"
 * [20] => "twenty"
 * ...
 * [100] => "hundred"
 * [1000] => "thousand"
 * [1000000] => "million"
 * ...
 *
 * @return SUCCESS if number was converted, FAILURE otherwise.
 */
int
convert_number_to_string( uint32_t numToConvert,
                          char* lookUpTable[],
                          uint32_t lookUpTableLen,
                          char** convertedNumber,
                          uint32_t* convertedNumberLen ) ;

/**
 * Break down the number into it's parts.
 *
 * @param[in] number Number to break down
 * @param[in] position Which decimal position to look at.
 *                     For first time, call with largest magnitude of the number.
 * @param[out] numberRepresentation Struct to store broken down number in.
 *
 */
int
break_down_number( uint32_t number,
                   uint32_t position,
                   char* lookUpTable[],
                   uint32_t lookUpTableLen,
                   char* convertedNumber,
                   uint32_t* convertedNumberLen ) ;

