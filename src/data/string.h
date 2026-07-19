/**
 * This check guards against redeclaring this file.
 */
#ifndef STRING
#define STRING

#include <stdint.h>

/**
 * The base struct that represents a string. This includes
 * the characters as well as the strings length.
 */
typedef struct  string {
   char* chars;
   uint32_t length;
} String;

/**
 * Creates an instance of String using the given char array
 * and length. It is on the user of this function to ensure
 * the length provided matches the size and initialzied
 * contents of the given char array.
 */
String* string_create(char* chars, uint32_t length);

#endif
