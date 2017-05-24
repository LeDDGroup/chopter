#pragma once

class Chopter {
  int x, y, width, height;
  int vspeed;
  int hspeed;
  void setPosition(int x, int y);
  void fly();
  void fall();
  void resetPosition();
public:
  Chopter(int x = 0, int y = 0, int width = 32, int height = 32);
  void move(bool fuel);
  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
};
