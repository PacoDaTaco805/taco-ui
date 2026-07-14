typedef struct label {
  Component component;
  String *text;
} Label;

int32_t label_hasChildren(Component*);

void setText(String*, Label*);

Label *createLabel(String* text) {
  Label *label = malloc(sizeof(Label));

  static const Component_V_Table v_table = {hasChildren};

  label->component.component_v_table = &v_table;

  return label;
}

int32_t label_hasChildren(Component* component) {
    return 0;
}

void label_setText(String* text, Label *label) {
    label->text = text;
}
