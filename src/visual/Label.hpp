#ifndef LABEL_HPP
#define LABEL_HPP

#include <SDL2pp/Texture.hh>
#include <SDL2/SDL_rect.h>
#include "../core/Point.hpp"

class Label {
  const char * text;
  SDL2pp::Texture texture;
  SDL2pp::Rect getDrawRect();
  SDL2pp::Rect rect;
public:
  enum VAlign { Top, Middle, Bottom };
  enum HAlign { Left, Center, Right };
  Label();
  ~Label();
  VAlign valign;
  HAlign halign;
  void draw();
  void setText(const char * text);
  const SDL2pp::Rect & getRect() const { return rect; };
  void setRect(const SDL2pp::Rect & other) { rect = other; };
};

#endif
