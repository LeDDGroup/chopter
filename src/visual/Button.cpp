#include <SDL2/SDL_ttf.h>
#include "Button.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"

void Button::draw(SDL_Surface * screen) {
  SDL_FillRect(screen, &rect, color);
}

bool Button::checkClick(const Point<int> &mousePosition) {
  return (mousePosition.x >= rect.x && mousePosition.y >= rect.y)
    && (mousePosition.x < (rect.x + rect.w) && mousePosition.y < (rect.y + rect.h));
}
