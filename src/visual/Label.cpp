#include "Label.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"
#include "../control/Environment.hpp"
using namespace SDL2pp;

extern Environment environment;

Label::Label(const char * str)
  : textComponent(str),
    valign(Top), halign(Left) {
}

void Label::setText(const char * str) {
  textComponent = Text(str);
}

void Label::draw() {
  textComponent.draw(align(rect, textComponent.GetSize(), halign, valign));
}
