#ifndef TEXTBUTTON_HPP
#define TEXTBUTTON_HPP

#include "Button.hpp"
#include "Text.hpp"
#include <string>

class TextButton: public Button {
  Text textComponent;
public:
  TextButton(const std::string &text = "TextButton",
             const SDL2pp::Rect &rect = SDL2pp::Rect(),
             const Uint32 bgColor = 0);
  void setText(const std::string &text) { textComponent = Text(text); };
  void draw();
};

#endif
