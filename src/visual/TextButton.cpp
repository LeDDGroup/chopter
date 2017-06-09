#include "TextButton.hpp"
#include "utils.hpp"

TextButton::TextButton(const std::string & text,
                       const SDL2pp::Rect &rect,
                       const Uint32 bgColor)
  : textComponent(text),
    Button(rect, bgColor) {
}

void TextButton::draw() {
  Button::draw();
  textComponent.draw(align((SDL2pp::Rect)(*this), textComponent.GetSize(), Center, Middle));
}
