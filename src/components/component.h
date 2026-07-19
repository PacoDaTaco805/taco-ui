/**
 * This check guards against redeclaring this file.
 */
#ifndef COMPONENT
#define COMPONENT

#include <stdint.h>

/**
 * The top most struct that all other UI components should
 * "implement".
 */
typedef struct component Component;

/**
 * A struct to hold function pointers that are required for
 * objects "implementing" the Component "interface".
 */
typedef struct component_v_table Component_V_Table;

struct component {
    const Component_V_Table *component_v_table;
};

struct component_v_table {
    int32_t (*hasChildren)(Component* component);
};

/**
 * Checks if the given component has a child.
 */
int32_t component_hasChild(Component* component);

/**
 * Prints all child components
 */
int32_t component_print(Component* component);

#endif
