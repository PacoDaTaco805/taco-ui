/**
 * The top most struct that all other UI components should
 * "implement".
 */
typedef struct component Component;

/**
 * A struct to hold function pointers that are required for
 * objects "implementing" the Component "interface".
 */
typedef struct component_v_table {
    int32_t (* hasChildren)(Component* component);
} Component_V_Table;

// Defining the forward declared Componet struct
struct component {
    const Component_V_Table* component_v_table;
};

int32_t component_hasChild(Component* component) {
    return component->component_v_table->hasChildren(component);
}

Model* component_buildModelTree(Component* component) {
    if (component_hasChild(component))
    {
        Component* children = component_getChildren();
    }
}
