#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "string.c"
#include "size.c"
#include "component.c"
#include "container.c"
#include "label.c"
#include "model.c"

int main() {
    Container* container = createContainer();

    String* string = string_create("hello", 5);

    int32_t hasChild = component_hasChild((Component*) container);

    printf("Container has child: %d", hasChild);

    Label* label = createLabel(string);
}
