#include <stdint.h>
#include <stdio.h>
#include "./data/string.h"
#include "./components/component.h"
#include "./components/container.h"
#include "./components/label.h"

int32_t main() {
    int32_t error = 0;

    Container container1;

    error = container_create(&container1);

    if (error != 0) {
        printf("Failed to create container...\n");
    }

    printf("Successfully created container...\n");

    Container container2;

    error =  container_create(&container2);

    if (error) {
        printf("Failed to create container...\n");
    }

    printf("Successfully created container...\n");

    String* string = string_create("hello", 5);

    Label label;

    error = label_create(string, &label);

    error = container_addComponent((Component*) &label, &container1);

    if (error == -1) {
       printf("Failed to add component to container...\n");
    }

    printf("Successfully added component to list...\n");

    componentList_print(container1.childComponents);
}
