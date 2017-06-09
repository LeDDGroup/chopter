#include "Sprite.hpp"
#include "../control/Environment.hpp"
#include <SDL2pp/Renderer.hh>

extern Environment environment;

Sprite::Sprite(const char * path, int amount, float speed)
  : texture(environment.renderer, path), amount(amount), speed(speed) {
  x = 0;
  y = 0;
  drawRect.w = texture.GetWidth();
  drawRect.h = texture.GetHeight() / amount;
}

void Sprite::update() {
  y += speed;
  while (y >= amount) {
    y -= amount;
  }
}

void Sprite::draw(const SDL2pp::Rect &rect) {
  drawRect.x = x; drawRect.y = (int) y * drawRect.h;
  environment.renderer.Copy(texture, drawRect, rect);
}
