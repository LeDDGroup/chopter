#include "Chopter.hpp"

const float Chopter::accel = 0.8;
const float Chopter::gravity = 1.3;

Chopter::Chopter(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->vspeed = 0;
  this->hspeed = 5;
  this->mxVspeed = 7;
  this->mnVspeed = -12;
}

void Chopter::updateSpeed() {
  if (status == fly) {
    vspeed -= accel;
  } else {
    vspeed += gravity;
  }
  if(vspeed > mxVspeed) {
    vspeed = mxVspeed;
  }
  if(vspeed < mnVspeed) {
    vspeed = mnVspeed;
  }
}

void Chopter::updatePosition() {
  x += hspeed;
  y += vspeed;

  y = ((int)y + 480) % 480;
  x = (int)x % 672;
}

void Chopter::setStatus(Status status) {
  this->status = status;
}

void Chopter::move(bool fuel) {
  setStatus(fuel ? fly : fall);
  updateSpeed();
  updatePosition();
};
