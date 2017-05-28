#ifndef TEXTBUTTON_HPP
#define TEXTBUTTON_HPP

#include "Button.hpp"
#include "Text.hpp"

class TextButton: public Button {
  Text textComponent;
public:
  TextButton(const char * text = "TextButton",
             const SDL2pp::Rect &rect = SDL2pp::Rect(),
             const Uint32 bgColor = 0);
  void setText(const char * text) { textComponent = Text(text); };
  void draw();
};

#endif
