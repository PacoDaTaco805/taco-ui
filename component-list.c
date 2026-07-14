#include <stdlib.h>
typedef struct component_list {
   int32_t currentSize;
   int32_t maxSize;
   Component* components;
} Component_list;

int32_t component_createList(int32_t initialSize, Component_list* componentList) {
    // We do not allow for a size of less than 0
    if (initialSize < 0) {
        return -1;
    }

    if (initialSize == 0) {
        componentList->components = NULL;
    } else {
        componentList = calloc(
            initialSize,
            sizeof(Component*) * initialSize);
    }

    componentList->maxSize = initialSize;

    componentList->currentSize = 0;

    return 0;
}

int32_t componentList_addItem(
    Component* component,
    Component_list* componentList) {
        if (componentList->currentSize == componentList->maxSize) {
            int32_t error = extendList();

            if (error == -1) {
                return -1;
            }
        }
}
