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
 * @param[in] key Key to use for the hash
 * @param[in] val Value to insert for the key
 * @param[in] valLen Length of the value
 */
void
hash_append( struct hash* hashHead,
             uint32_t key,
             char* val, uint32_t valLen ) ;

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

