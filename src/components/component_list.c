#include <stdint.h>
#include <stdio.h>
#include "../data/list.h"
#include "component.h"
#include "component_list.h"

/**
 * Adds the given component to the given component list.
 */
int32_t componentList_add(Component* component, Component_List *list) {
    if (component == NULL || list == NULL) {
        return -1;
    }

    return list_add(component, list->list);
}

/**
 * Prints the given component list.
 */
void componentList_print(Component_List *list) {
  List *tmpList = list->list;
  for (int itemIndex = 0; itemIndex < tmpList->currentSize; tmpList++) {
    printf("---\n");

    Component *component = (Component *)(tmpList->items[itemIndex]);

    printf("Has children: %d",
           component->component_v_table->hasChildren(component));
  }
}
