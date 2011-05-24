#include "hash.h"

#include <stdint.h>
#include <string.h>
#include <malloc.h>

void
hash_append( struct hash* hashHead,
             uint32_t key,
             char* val, uint32_t valLen ) {
  struct hash* new_element = malloc( sizeof(struct hash) ) ;
  struct hash* cur = hashHead ;
  if( NULL == val || 0 == valLen ) {
    return ;
  }
  //
  new_element->key = key ;
  strncpy( new_element->val, val, valLen ) ;
  new_element->valLen = valLen ;
  new_element->next = NULL ;
  //
  if( NULL == hashHead ) {      // Create new hash
    hashHead = new_element ;
  } else {                      // Append to end of existing hash
    while( NULL != cur->next ) {
      cur = cur->next ;
    }
    //
    cur->next = new_element ;
  }
}

struct hash*
hash_find_by_key( struct hash* hashHead, uint32_t key ) {
  struct hash* cur = hashHead ;
  if( NULL == hashHead ) {
    return NULL ;
  }
  //
  while( NULL != cur->next ) {
    if( key == cur->key ) {
      return cur ;
    }
    //
    cur = cur->next ;
  }
  //
  return NULL ;
}

