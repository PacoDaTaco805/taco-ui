#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static int32_t resizeList(List *);

int32_t list_create(int32_t initialSize, List *list) {
  if (initialSize < 0) {
    return -1;
  }

  list = malloc(sizeof(List));

  list->items = calloc(initialSize, sizeof(void *) * initialSize);

  list->currentSize = 0;

  list->maxSize = initialSize;

  return 0;
}

int32_t list_add(void *item, List *list) {
    printf( "Checking if we need to resize list...\n");

    if (list->currentSize >= list->maxSize) {
        printf("Resizing the list...");

        int error = resizeList(list);

        if (error != 0) {
            return -1;
        }
    }

  list->items[list->currentSize] = item;

  list->currentSize++;

  return 0;
}

/**
 * Removes the item pointed to by item from the list if it
 * is present or simply returns if the item is not in the
 * list. The item not being in the list is still counted as
 * a success and 0 will be returned. If item is NULL, the
 * call will fail and -1 will be returned.
 */
int32_t list_remove(void *item, List *list) {
  if (item == NULL) {
    return -1;
  }

  if (list->currentSize <= 0) {
    return 0;
  }

  for (int32_t itemIndex = 0; itemIndex < list->currentSize; itemIndex++) {
    if (list->items[itemIndex] != item) {
      continue;
    }

    if (itemIndex == list->maxSize - 1) {
      list->items[itemIndex] = NULL;
    } else {
      // memcpy(list->items + itemIndex + 1, list->items,
             //list->currentSize - itemIndex);

      list->items[list->currentSize] = NULL;
    }

    list->currentSize--;

    break;
  }

  return 0;
}

/**
 * Resizes the given list by doubling its max capacity.
 * The maximum size that List allows for is 2^32 items.
 * So if you attempt to double with a current max size
 * greater than 2^32 / 2 it will increase the size to 2^32.
 * Further attempts to resize will fail and return -1
 */
static int32_t resizeList(List *list) {
  if (list->maxSize == INT32_MAX) {
    return -1;
  }

  int32_t newMaxSize =
      (list->maxSize > (INT32_MAX / 2)) ? INT32_MAX : list->maxSize * 2;

  void **newList = malloc(sizeof(void *) * newMaxSize);

  // memcpy(newList, list->items, list->currentSize);

  list->items = newList;

  return 0;
}
