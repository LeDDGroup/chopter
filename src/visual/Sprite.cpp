#include "Sprite.hpp"
#include "../control/Environment.hpp"
#include <SDL2pp/Renderer.hh>

extern Environment environment;

Sprite::Sprite(const char * path)
  : texture(environment.renderer, path) {
}

void Sprite::draw(const SDL2pp::Rect &rect) {
  environment.renderer.Copy(texture, SDL2pp::NullOpt, rect);
}
