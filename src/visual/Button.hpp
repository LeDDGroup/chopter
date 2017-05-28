#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include "../core/Point.hpp"

class Button {
public:
  Button();
  bool selected;
  SDL_Rect rect;
  Uint32 color;
  void draw();
  bool checkClick(const Point<int> &mousePosition);
};

#endif
