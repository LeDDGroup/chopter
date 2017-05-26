#include "Chopter.hpp"

const float Chopter::accel = 1.3;
const float Chopter::gravity = 2.0;

Chopter::Chopter(const Point<float> &position, const Point<int> &size)
  : position(position), size(size) {
  speed = Point<float>(10, 0);
  this->mxVspeed = -9;
  this->mnVspeed = 15;
}

void Chopter::updateSpeed() {
  if (status == fly) {
    speed.y -= accel;
  } else {
    speed.y += gravity;
  }
  if(speed.y < mxVspeed) {
    speed.y = mxVspeed;
  }
  if(speed.y > mnVspeed) {
    speed.y = mnVspeed;
  }
}

void Chopter::updatePosition() {
  position = position + speed;
}

void Chopter::setStatus(Status status) {
  this->status = status;
}

void Chopter::invertSpeed() {
  speed.y *= -1;
}

void Chopter::move(bool fuel) {
  setStatus(fuel ? fly : fall);
  updateSpeed();
  updatePosition();
};
