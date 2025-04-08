#line 1 "/Users/martinflataker/Desktop/Prog_Semester_4/Elsys_semester_4_samlet/7_april/Arduino/testfisk_organisert_7_april_copy_2/subprojects/animationwindow/src/widgets/CheckBox.cpp"
#include "widgets/CheckBox.h"


TDT4102::CheckBox::CheckBox(TDT4102::Point location, unsigned int width, unsigned int height, std::string label) :
    TDT4102::Widget(location, width, height),
    label{std::move(label)} {}

void TDT4102::CheckBox::update(nk_context *context) {
    if (nk_input_has_mouse_click_down_in_rect(&context->input, NK_BUTTON_RIGHT, context->current->layout->clip, true)) {
        isSelected_ = false;
    }
    if (nk_input_has_mouse_click_down_in_rect(&context->input, NK_BUTTON_LEFT, context->current->layout->clip, true)) {
        isSelected_ = true;
    }

    struct nk_style* s = &context->style;    
    nk_style_push_color(context, &s->checkbox.text_normal, labelColor);
    nk_style_push_color(context, &s->checkbox.text_hover, labelColor);
    nk_style_push_color(context, &s->checkbox.text_active, labelColor);
    nk_style_push_style_item(context, &s->checkbox.normal, nk_style_item_color(checkBoxColor));
    nk_style_push_style_item(context, &s->checkbox.hover, nk_style_item_color(checkBoxColorHover));
    nk_style_push_style_item(context, &s->checkbox.active, nk_style_item_color(checkBoxColorActive));

    if (nk_checkbox_label(context, label.data(), &isSelected_)) {
        isSelected_ = true;
        fire();
    }
    
    nk_style_pop_color(context);
    nk_style_pop_color(context);
    nk_style_pop_color(context);
    nk_style_pop_style_item(context);
    nk_style_pop_style_item(context);
    nk_style_pop_style_item(context);

}

void TDT4102::CheckBox::setLabel(std::string newLabel) {
    label = newLabel;
}

bool TDT4102::CheckBox::isSelected() const {
    return (bool)isSelected_;
}
