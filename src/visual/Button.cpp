#include "Button.hpp"

void Button::draw(SDL_Surface * surface) {
  SDL_FillRect(surface, &rect, color);
  // TODO draw text
}

bool Button::checkClick(const Point<int> &mousePosition) {
  return (mousePosition.x >= rect.x && mousePosition.y >= rect.y)
    && (mousePosition.x < (rect.x + rect.w) && mousePosition.y < (rect.y + rect.h));
}
