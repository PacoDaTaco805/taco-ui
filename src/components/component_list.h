#ifndef COMPONENT_LIST
#define COMPONENT_LIST

#include "../data/list.h"
#include "component.h"

/**
 * A list for holding components.
 */
typedef struct component_list Component_List;

/**
 * Defining the component_list type.
 */
struct component_list {
    List* list;
};

int32_t componentList_add(Component* component, Component_List *list);

void componentList_print(Component_List *list);

#endif
