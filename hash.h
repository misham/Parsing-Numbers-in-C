#ifndef HASH_H__
#define HASH_H__

#include <stdint.h>

struct hash {
  uint32_t key ;
  char* val ;
  uint32_t valLen ;

  struct hash* next ;
} ;

/**
 * Appends a new element to the hash
 *
 * @param[in] hashHead First element of the hash to append to
 * @param[in] elem Element to append
 */
void
hash_append( struct hash** hashHead,
             struct hash* elem ) ;

/**
 * Finds the hash value given a key
 *
 * @param[in] hashHead First element of the hash to append to
 * @param[in] key Key to find
 * @param[in] keyLen Length of the key to find
 *
 * @return Hash element identified by the key or NULL
 */
struct hash*
hash_find_by_key( struct hash* hashHead, uint32_t key ) ;

#endif

