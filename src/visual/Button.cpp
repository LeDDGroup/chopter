#include <SDL2/SDL_ttf.h>
#include "Button.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"
#include "../control/Environment.hpp"

extern Environment environment;

void Button::draw() {
  SDL_Color sdlcolor;
  sdlcolor.a = 0xFF;
  sdlcolor.b = 0xFF & (color);
  sdlcolor.g = 0xFF & (color >> 8);
  sdlcolor.r = 0xFF & (color >> 12);
  environment.renderer.SetDrawColor(sdlcolor.r, sdlcolor.g, sdlcolor.b, sdlcolor.a);
  environment.renderer.FillRect(SDL2pp::Rect(rect));
  if (selected) {
    environment.renderer.SetDrawColor(255, 255, 255, 255);
    environment.renderer.DrawRect(SDL2pp::Rect(rect));
  }
}

bool Button::checkClick(const Point<int> &mousePosition) {
  return (mousePosition.x >= rect.x && mousePosition.y >= rect.y)
    && (mousePosition.x < (rect.x + rect.w) && mousePosition.y < (rect.y + rect.h));
}
