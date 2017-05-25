#include "Button.hpp"

void Button::draw(SDL_Surface * surface) {
  SDL_FillRect(surface, &rect, color);
}
