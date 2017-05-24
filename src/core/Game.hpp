#pragma once
#include "Chopter.hpp"
#include "Map.hpp"


class Game {
  unsigned long long int steps;
  int verticalChopterSteps;
  int horizontalChopterSteps;
  void increaseStep ();
  void moveChopter (bool fuel);
  void checkColition ();
  void removeBlocks ();
  Chopter chopter;
  Map map;
public:
  Game();
  void onStep(bool buttonStatus);
};
