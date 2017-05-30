#include "Sprite.hpp"
#include "../control/Environment.hpp"

extern Environment environment;

Sprite::Sprite(const char * path)
  : texture(environment.renderer, path) {
}
