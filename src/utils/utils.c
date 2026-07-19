#ifndef UTILS
#define UTILS

#include <stdlib.h>
#include <stdint.h>

int32_t utils_memcpy(void* source, void* destination, size_t size) {
    void* beginning = source;

    void* end = source + size;

    if (beginning >= destination || destination >= end) {
        return -1;
    }
}

#endif
