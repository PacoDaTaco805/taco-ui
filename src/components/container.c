#include <stdint.h>
#include <stdlib.h>
#include "container.h"

/**
 * Checks if this container has any child components. 1 is
 * returned if it doesn, otherwise 0 is returned.
 */
int32_t hasChildren(Component* component) {
    if (component == NULL) {
        return -1;
    }

    // We can safely cast the component to a container here
    // as the vtable will only direct us to this function if
    // the component is a container.
    Container *container = (Container*)component;

    // If the childComponents pointer is not null it implies
    // there is a list of components there
    return container->childComponents->list->currentSize > 0;
}

/**
 * Constructs a default instance of Container.
 */
int32_t container_create(Container* container) {
    // This is static so as to share the v-table among
    // all Containers
    static const Component_V_Table v_table = {hasChildren};

    container->component.component_v_table = &v_table;

    List* list = malloc(sizeof(List));

    list_create(8, list);

    Component_List* component_list = malloc(sizeof(Component_List));

    component_list->list = list;

    container->childComponents = component_list;

    return 0;
}

int32_t container_addComponent(Component* component, Container* container) {
    if (component == NULL || container == NULL) {
        return -1;
    }

    return componentList_add(component, container->childComponents);
}
