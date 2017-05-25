#include <SDL2/SDL_ttf.h>
#include "Button.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"

TTF_Font * Button::font = 0;

Button::Button()
  : text(), surface(0) {
}

Button::~Button() {
  clearSurface();
}

void Button::clearSurface() {
  if (surface) {
    SDL_FreeSurface(surface);
    surface = 0;
  }
}

void Button::setText(const std::string & str) {
  text = str;
  SDL_Color color;
  color.r = 255; color.g = 255;
  color.b = 255; color.a = 255;
  clearSurface();
  surface = TTF_RenderText_Solid(font, text.c_str(), color);
  if (surface == 0) {
    Logic::throwError();
    return;
  }
  fontrect.x = 0; fontrect.y = 0;
  fontrect.w = surface->w; fontrect.h = surface->h;
}

void Button::draw(SDL_Surface * screen) {
  SDL_Rect cpy = fontrect;
  cpy.x = rect.x + (rect.w - fontrect.w) / 2;
  cpy.y = rect.y + (rect.h - fontrect.h) / 2;
  SDL_FillRect(screen, &rect, color);
  SDL_BlitSurface(surface, &fontrect,
                  screen, &cpy);
}

bool Button::checkClick(const Point<int> &mousePosition) {
  return (mousePosition.x >= rect.x && mousePosition.y >= rect.y)
    && (mousePosition.x < (rect.x + rect.w) && mousePosition.y < (rect.y + rect.h));
}
