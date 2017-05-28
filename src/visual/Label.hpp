#ifndef LABEL_HPP
#define LABEL_HPP

#include <SDL2pp/Texture.hh>
#include <SDL2/SDL_rect.h>
#include "../core/Point.hpp"

class Label {
  const char * text;
  SDL2pp::Texture texture;
  SDL2pp::Rect getDrawRect();
public:
  enum VAlign { Top, Middle, Bottom };
  enum HAlign { Left, Center, Right };
  Label();
  ~Label();
  SDL2pp::Rect rect;
  VAlign valign;
  HAlign halign;
  void draw();
  void setText(const char * text);
};

#endif
