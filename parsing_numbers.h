#ifndef PARSING_NUMBERS_H__
#define PARSING_NUMBERS_H__

#include "hash.h"

/**
 * Populate look-up table with string values.
 *
 * @param[in,out] lookUpTable Valid pointer for a hash structure. Hash
 *                        structure will be created automatically.
 */
void
populate_lookup_table( struct hash** lookUpTable ) ;

/**
 * Prints the contents of the hash table.
 *
 * @param[in] lookUpTable Look-up table to print
 */
void
print_hash( struct hash* lookUpTable ) ;


#endif

