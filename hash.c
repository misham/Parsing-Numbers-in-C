#include "hash.h"

#include <stdint.h>
#include <string.h>
#include <malloc.h>

void
hash_append( struct hash** hashHead,
             struct hash* elem ) {
  struct hash* cur = *hashHead ;
  if( NULL == elem || NULL == hashHead ) {
    return ;
  }
  //
  if( NULL == cur ) {      // Create new hash
    *hashHead = elem ;
  } else {                      // Append to end of existing hash
    while( NULL != cur->next ) {
      cur = cur->next ;
    }
    //
    cur->next = elem ;
  }
}

struct hash*
hash_find_by_key( struct hash* hashHead, uint32_t key ) {
  struct hash* cur = hashHead ;
  if( NULL == hashHead ) {
    return NULL ;
  }
  //
  while( NULL != cur ) {
    if( key == cur->key ) {
      return cur ;
    }
    //
    cur = cur->next ;
  }
  //
  return NULL ;
}

