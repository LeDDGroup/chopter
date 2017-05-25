#ifndef CHOPTER_HPP
#define CHOPTER_HPP

#include "Point.hpp"

class Chopter {
  static const float accel;
  static const float gravity;
  enum Status { fly, fall };
  Point<float> position;
  Point<int> size;
  Point<float> speed;
  float mxVspeed, mnVspeed;
  Status status;
  void setStatus(Status status);
  void updateSpeed();
  void updatePosition();
public:
  Chopter(const Point<float> &position = Point<float>(0, 320), const Point<int> &size = Point<int>(32, 32));
  void move(bool fuel);
  void invertSpeed();
  int getX() const { return position.x; }
  int getY() const { return position.y; }
  int getWidth() const { return size.x; }
  int getHeight() const { return size.y; }
};

#endif
