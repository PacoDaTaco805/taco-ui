#include <stdint.h>
#include "label.h"

int32_t label_create(String* text, Label* label) {
    static const Component_V_Table v_table = {label_hasChildren};

    label->component.component_v_table = &v_table;

    return 0;
}

int32_t label_hasChildren(Component* component) {
    return 0;
}

void label_setText(String* text, Label *label) {
    label->text = text;
}
