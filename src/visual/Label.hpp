#ifndef LABEL_HPP
#define LABEL_HPP

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include "../core/Point.hpp"

class Label {
  const char * text;
  SDL_Surface * surface;
  SDL_Rect fontrect;
  void clearSurface();
public:
  Label();
  ~Label();
  SDL_Rect rect;
  void draw(SDL_Surface * surface);
  void setText(const char * text);
};

#endif
