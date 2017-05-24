#include "Chopter.hpp"

Chopter::Chopter(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->vspeed = 0;
  this->hspeed = 1;
}

void Chopter::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

void Chopter::fly() {
  vspeed -= 1;
  setPosition(x + hspeed, y + vspeed);
}

void Chopter::fall() {
  vspeed += 2;
  setPosition(x + hspeed, y + vspeed);
}

void Chopter::resetPosition() {
  setPosition(0, y);
}

void Chopter::move(bool fuel) {
  if (fuel) {
    fly();
  }
  else {
    fall();
  }
};
