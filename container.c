/**
 * A Component that contains other components.
 */
typedef struct container {
   Component component;
   Component* childComponents;
} Container;

/**
 * Checks if this container has any child components. 1 is
 * returned if it doesn, otherwise 0 is returned.
 */
int32_t hasChildren(Component* component) {
    // We can safely cast the component to a container here
    // as the vtable will only direct us to this function if
    // the component is a container.
    Container* container = (Container*) component;

    // If the childComponents pointer is not null it implies
    // there is a list of components there
    return container->childComponents != NULL;
}

/**
 * Constructs a default instance of Container.
 */
Container* createContainer() {
    Container* container =  malloc(sizeof(Container));

    // This is static so as to share the v-table among
    // all Containers
    static const Component_V_Table v_table = {hasChildren};

    container->component.component_v_table = &v_table;

    return container;
}
