/**
 * This check guards against redeclaring this file.
 */
#ifndef SIZE_2D
#define SIZE_2D

#include <stdint.h>

/**
 * Represents the size of something in 2 dimensions.
 */
typedef struct {
   uint32_t x;
   uint32_t y;
} Size2D;

#endif
