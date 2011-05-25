#include "parsing_numbers.h"
#include "convert_number.h"
#include "hash.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int
main( int argc, char* argv[] ) {
	uint32_t number_to_convert = 0 ;
	struct hash* look_up_table = NULL ;
	char* result = NULL ;
	//
  populate_lookup_table( &look_up_table ) ;
  //print_hash( look_up_table ) ;
	//
  number_to_convert = 7 ;
  result = convert_number_to_string( number_to_convert,
                                     0,
                                     look_up_table ) ;
	if( 0 == strncmp(result, "seven", strlen("seven")) ) {
		printf( "Pass\t" ) ;
	} else {
		printf( "Fails\t" ) ;
	}
  printf( "%d -> %s\n", number_to_convert, result ) ;
  //
  number_to_convert = 20 ;
  result = convert_number_to_string( number_to_convert,
                                     0,
                                     look_up_table ) ;
	if( 0 == strncmp(result, "twenty", strlen("twenty")) ) {
		printf( "Pass\t" ) ;
	} else {
		printf( "Fails\t" ) ;
	}
  printf( "%d -> %s\n", number_to_convert, result ) ;
  //
  number_to_convert = 127 ;
  result = convert_number_to_string( number_to_convert,
                                     0,
                                     look_up_table ) ;
	if( 0 == strncmp(result, "onehundredtwentyseven", strlen("onehundredtwentyseven")) ) {
		printf( "Pass\t" ) ;
	} else {
		printf( "Fails\t" ) ;
	}
  printf( "%d -> %s\n", number_to_convert, result ) ;
	//
	number_to_convert = 12456 ;
  result = convert_number_to_string( number_to_convert,
                                     0,
                                     look_up_table ) ;
	if( 0 == strncmp(result, "twelvethousandfourhundredfiftysix", strlen("twelvethousandfourhundredfiftysix")) ) {
		printf( "Pass\t" ) ;
	} else {
		printf( "Fails\t" ) ;
	}
  printf( "%d -> %s\n", number_to_convert, result ) ;
	//
	return EXIT_SUCCESS ;
}

void
create_hash_elem( struct hash** elem,  uint32_t key, char* val, uint32_t valLen ) {
  struct hash* my_elem = malloc( sizeof(struct hash) ) ;
  //
  if( NULL == val || 0 == valLen ) {
    free( elem ) ;
    elem = NULL ;
    return ;
  }
  //
  my_elem->key = key ;
  my_elem->val = malloc( sizeof(char) * (valLen + 1) ) ;
  strncpy( my_elem->val, val, valLen ) ;
  my_elem->val[valLen] = '\0' ;
  my_elem->valLen = valLen ;
  my_elem->next = NULL ;
  //
  *elem = my_elem ;
}

void
populate_lookup_table( struct hash** lookUpTable ) {
  struct hash* elem = NULL ;
  //
  {
    char str[] = "zero" ;
    create_hash_elem( &elem, 0, str, strlen(str) ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "one" ;
    create_hash_elem( &elem, 1, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "two" ;
    create_hash_elem( &elem, 2, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "three" ;
    create_hash_elem( &elem, 3, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "four" ;
    create_hash_elem( &elem, 4, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "five" ;
    create_hash_elem( &elem, 5, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "six" ;
    create_hash_elem( &elem, 6, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "seven" ;
    create_hash_elem( &elem, 7, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "eight" ;
    create_hash_elem( &elem, 8, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "nine" ;
    create_hash_elem( &elem, 9, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "ten" ;
    create_hash_elem( &elem, 10, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "eleven" ;
    create_hash_elem( &elem, 11, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "twelve" ;
    create_hash_elem( &elem, 12, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "thirteen" ;
    create_hash_elem( &elem, 13, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "fourteen" ;
    create_hash_elem( &elem, 14, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "fifteen" ;
    create_hash_elem( &elem, 15, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "sixteen" ;
    create_hash_elem( &elem, 16, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "seventeen" ;
    create_hash_elem( &elem, 17, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "eighteen" ;
    create_hash_elem( &elem, 18, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "nineteen" ;
    create_hash_elem( &elem, 19, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "twenty" ;
    create_hash_elem( &elem, 20, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "thirty" ;
    create_hash_elem( &elem, 30, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "fourty" ;
    create_hash_elem( &elem, 40, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "fifty" ;
    create_hash_elem( &elem, 50, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "sixty" ;
    create_hash_elem( &elem, 60, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "seventy" ;
    create_hash_elem( &elem, 70, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "eighty" ;
    create_hash_elem( &elem, 80, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "ninety" ;
    create_hash_elem( &elem, 90, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "hundred" ;
    create_hash_elem( &elem, 100, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }
  //
  {
    char str[] = "thousand" ;
    create_hash_elem( &elem, 1000, str, strlen(str) + 1 ) ;
    hash_append( lookUpTable, elem ) ;
  }

}

void
print_hash( struct hash* lookUpTable ) {
  struct hash* cur = lookUpTable ;
  if( NULL == lookUpTable ) {
    return ;
  }
  //
  while( NULL != cur ) {
    printf( "%d -> %s\n", cur->key, cur->val ) ;
    //
    cur = cur->next ;
  }
}

