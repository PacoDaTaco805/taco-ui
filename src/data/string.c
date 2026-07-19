#include <stdlib.h>
#include "string.h"

String* string_create(char* chars, uint32_t length) {
    // Let's just grab the size of the struct and throw it
    // in a static varibale so we don't have to resolve this
    // everytime a string is created
    static size_t structSize = sizeof(String);

    String* string = calloc(structSize, structSize);

    size_t string_length = sizeof(char) * length;

    char* temp_chars = calloc(string_length, string_length);

    for (int currentIndex = 0; currentIndex < length; currentIndex++){
        temp_chars[currentIndex] = chars[currentIndex];
    }

    string->chars = temp_chars;

    string->length = length;

    return string;
}

uint32_t string_get_null_terminated_length(char* chars) {
    uint32_t length = 0;

    while (chars[length] != '\0') {
        if (length == UINT32_MAX)
        {
            return -1;
        }

        length ++;
    }

    return length;
}
