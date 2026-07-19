#include <stdint.h>
#include <stdio.h>
#include "component.h"

int32_t component_hasChild(Component* component) {
    if (component == NULL)
    {
        return -1;
    }

    printf("Checking if the given component has a child...\n");

    return component->component_v_table->hasChildren(component);
}
