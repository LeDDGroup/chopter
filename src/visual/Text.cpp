#include "Text.hpp"
#include "../control/Environment.hpp"

extern Environment environment;
const SDL_Color Text::textColor = SDL_Color{255, 255, 255, 255};

Text::Text(const char * str)
  : text(str),
    SDL2pp::Texture(environment.renderer,
                    environment.font.RenderText_Solid(text, textColor)) {
}

void Text::draw(const SDL2pp::Rect &rect) {
  environment.renderer.Copy(*this, SDL2pp::NullOpt, rect);
}
