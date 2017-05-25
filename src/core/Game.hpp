#ifndef GAME_HPP
#define GAME_HPP

#include "Chopter.hpp"
#include "Map.hpp"


class Game {
  Chopter chopter;
  Map map;
  bool done;
  int blockWidth;
  int horizontalChopterSteps;
  int verticalChopterSteps;
  unsigned long long int steps;
  void checkColition();
  void increaseStep();
  void moveChopter(bool fuel);
  void updateBlocks();
  void finish(); // TODO implement
public:
  Game();
  void onStep(bool buttonStatus);
  const Chopter & getChopter() const { return this->chopter; }
  const Map & getMap() const { return this->map; }
  bool hasFinished() const { return this->done; }
  void start(); // TODO implement
};

#endif
