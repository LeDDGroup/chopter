#include <SDL2/SDL_ttf.h>
#include "Label.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"

TTF_Font * Label::font = 0;

Label::Label()
  : text(), surface(0) {
}

Label::~Label() {
  clearSurface();
}

void Label::clearSurface() {
  if (surface) {
    SDL_FreeSurface(surface);
    surface = 0;
  }
}

void Label::setText(const char * str) {
  text = str;
  SDL_Color color;
  color.r = 255; color.g = 255;
  color.b = 255; color.a = 255;
  clearSurface();
  surface = TTF_RenderText_Solid(font, text, color);
  if (surface == 0) {
    Logic::throwError();
    return;
  }
  fontrect.x = 0; fontrect.y = 0;
  fontrect.w = surface->w; fontrect.h = surface->h;
}

void Label::draw(SDL_Surface * screen) {
  SDL_Rect cpy = fontrect;
  cpy.x = rect.x + (rect.w - fontrect.w) / 2;
  cpy.y = rect.y + (rect.h - fontrect.h) / 2;
  SDL_BlitSurface(surface, &fontrect,
                  screen, &cpy);
}
