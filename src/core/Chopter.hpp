#ifndef CHOPTER_HPP
#define CHOPTER_HPP

class Chopter {
  static const float accel = 0.8;
  static const float gravity = 1.3;
  enum Status { fly, fall };
  float x, y;
  int width, height;
  float vspeed, hspeed;
  float mxVspeed, mnVspeed;
  Status status;
  void setStatus(Status status);
  void updateSpeed();
  void updatePosition();
public:
  Chopter(int x = 0, int y = 0, int width = 32, int height = 32);
  void move(bool fuel);
  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
};

#endif
