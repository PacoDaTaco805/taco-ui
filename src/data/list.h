/**
 * This check guards against redeclaring this file.
 */
#ifndef LIST
#define LIST

#include <stdint.h>

typedef struct {
    int32_t currentSize;
    int32_t maxSize;
    void** items;
} List;

/**
 * Creates a new list with an initial max size of
 * "initialSize" and stores its starting address in "list".
 */
int32_t list_create(int32_t initialSize, List* list);

/**
 * Adds an item pointed to by "item" to the given list
 * pointed to by "list". Will automatically resize the list
 * if the current array is full with 2^32 being the maximum
 * size the list can be.
 */
int32_t list_add(void* item, List* list);

int32_t list_remove(void* item, List* list);

int32_t list_clear(List* list);

#endif
