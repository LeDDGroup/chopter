#pragma once

class Chopter {
  enum Status { fly, fall };
  int x, y, width, height;
  int vspeed;
  int hspeed;
  Status status;
  void setStatus(Status status);
  void updateSpeed();
  void updatePosition();
  void resetPosition();
public:
  Chopter(int x = 0, int y = 0, int width = 32, int height = 32);
  void move(bool fuel);
  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
};
