#pragma once

class Chopter {
  int x, y, width, height;
  int horizontalSpeed, verticalSpeed, fallSpeed;
  void setPosition (int x, int y);
  void fly ();
  void fall ();
  void resetPosition ();
public:
  Chopter (int x = 0, int y = 0, int width = 32, int height = 32);
  void move (bool fuel);
  int getX ();
  int getY ();
  int getWidth ();
  int getHeight ();
};
