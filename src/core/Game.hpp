#pragma once
#include "Chopter.hpp"
#include "Map.hpp"


class Game {
  unsigned long long int steps;
  int chopterStep;
  int mapStep;
  bool canChopterMove () const;
  bool canMapMove () const;
  Chopter chopter;
  Map map;
public:
  Game();
  void onStep(bool buttonStatus);
};
