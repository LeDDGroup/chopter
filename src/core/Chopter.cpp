#include "Chopter.hpp"

const float Chopter::accel = 0.8;
const float Chopter::gravity = 1.3;

Chopter::Chopter(const Point<float> &position, const Point<int> &size)
  : position(position), size(size) {
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
  position.x += hspeed;
  position.y += vspeed;

  position.y = ((int)position.y + 480) % 480;
  position.x = (int)position.x % 672;
}

void Chopter::setStatus(Status status) {
  this->status = status;
}

void Chopter::invertSpeed() {
  vspeed *= -1;
}

void Chopter::move(bool fuel) {
  setStatus(fuel ? fly : fall);
  updateSpeed();
  updatePosition();
};
