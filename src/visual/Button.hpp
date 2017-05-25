#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>

class Button {
public:
  SDL_Rect rect;
  Uint32 color;
  void draw(SDL_Surface * surface);
};

#endif
