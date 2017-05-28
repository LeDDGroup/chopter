#ifndef LABEL_HPP
#define LABEL_HPP

#include <SDL2pp/Texture.hh>
#include <SDL2/SDL_rect.h>
#include "../core/Point.hpp"

class Label {
  const char * text;
  SDL2pp::Texture texture;
public:
  Label();
  ~Label();
  SDL2pp::Rect rect;
  void draw();
  void setText(const char * text);
};

#endif
