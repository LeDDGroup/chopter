#include "Text.hpp"
#include "../control/Environment.hpp"

extern Environment environment;
const SDL_Color Text::textColor = SDL_Color{255, 255, 255, 255};

Text::Text(const std::string &text)
  : text(text),
    SDL2pp::Texture(environment.renderer,
                    environment.font.RenderText_Solid(text, textColor)) {
}

void Text::draw(SDL2pp::Rect rect) {
  environment.renderer.Copy(*((SDL2pp::Texture*)this), SDL2pp::NullOpt, rect);
}
