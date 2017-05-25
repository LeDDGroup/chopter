#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include "../core/Point.hpp"

class Button {
  std::string text;
  SDL_Surface * surface;
  SDL_Rect fontrect;
  void clearSurface();
public:
  Button();
  ~Button();
  static TTF_Font *font;
  SDL_Rect rect;
  Uint32 color;
  void draw(SDL_Surface * surface);
  bool checkClick(const Point<int> &mousePosition);
  void setText(const std::string & str);
};

#endif
