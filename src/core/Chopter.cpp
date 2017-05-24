#include "Chopter.hpp"

Chopter::Chopter(int x, int y, int height, int widht) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  horizontalSpeed = 1;
  verticalSpeed = 1;
  fallSpeed = 1;
}

void Chopter::setPosition (int x, int y) {
  this->x = x;
  this->y = y;
}

void Chopter::fly () {
  setPosition (x + horizontalSpeed, y - fallSpeed);
}

void Chopter::fall () {
  setPosition (x + horizontalSpeed, y + verticalSpeed);
}

void Chopter::resetPosition () {
  setPosition (0, y);
}

void Chopter::move (bool fuel) {
  if (fuel) {
    fly ();
  }
  else {
    fall ();
  }
  resetPosition ();
};
