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
  // TODO implement
}

void Button::draw(SDL_Surface * surface) {
  SDL_FillRect(surface, &rect, color);
  // TODO draw text
}

bool Button::checkClick(const Point<int> &mousePosition) {
  return (mousePosition.x >= rect.x && mousePosition.y >= rect.y)
    && (mousePosition.x < (rect.x + rect.w) && mousePosition.y < (rect.y + rect.h));
}
