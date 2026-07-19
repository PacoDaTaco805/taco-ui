/**
 * This check guards against redeclaring this file.
 */
#ifndef CONTAINER
#define CONTAINER

#include "component.h"
#include "component_list.h"

/**
 * A Component that contains other components.
 */
typedef struct container {
    Component component;
    Component_List *childComponents;
} Container;

int32_t container_create(Container* container);

int32_t container_addComponent(Component* component, Container* container);

#endif
