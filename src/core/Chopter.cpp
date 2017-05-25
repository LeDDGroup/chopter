#include "Chopter.hpp"

const float Chopter::accel = 0.8;
const float Chopter::gravity = 1.3;

Chopter::Chopter(const Point<float> &position, const Point<int> &size)
  : position(position), size(size) {
  speed = Point<float>(5, 0);
  this->mxVspeed = 7;
  this->mnVspeed = -12;
}

void Chopter::updateSpeed() {
  if (status == fly) {
    speed.y -= accel;
  } else {
    speed.y += gravity;
  }
  if(speed.y > mxVspeed) {
    speed.y = mxVspeed;
  }
  if(speed.y < mnVspeed) {
    speed.y = mnVspeed;
  }
}

void Chopter::updatePosition() {
  position.x += speed.x;
  position.y += speed.y;

  position.y = ((int)position.y + 480) % 480;
  position.x = (int)position.x % 672;
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
