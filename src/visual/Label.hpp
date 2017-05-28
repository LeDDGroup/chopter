#ifndef LABEL_HPP
#define LABEL_HPP

#include "Text.hpp"
#include "../core/Point.hpp"
#include <SDL2pp/Texture.hh>
#include <SDL2/SDL_rect.h>

class Label {
public:
  enum VAlign { Top, Middle, Bottom };
  enum HAlign { Left, Center, Right };
private:
  Text textComponent;
  SDL2pp::Rect getDrawRect();
  SDL2pp::Rect rect;
  VAlign valign;
  HAlign halign;
public:
  Label(const char * str = "Text");
  void draw();
  void setText(const char * text);
  const SDL2pp::Rect & getRect() const { return rect; };
  void setRect(const SDL2pp::Rect & other) { rect = other; };
  void setHAlign(HAlign align) { halign = align; }
  void setVAlign(VAlign align) { valign = align; }
};

#endif
