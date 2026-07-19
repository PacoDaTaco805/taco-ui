#ifndef LABEL
#define LABEL

#include "../data/string.h"
#include "component.h"

typedef struct label {
    Component component;
    String *text;
} Label;

int32_t label_create(String* text, Label* label);

int32_t label_hasChildren(Component*);

void setText(String*, Label*);

#endif
