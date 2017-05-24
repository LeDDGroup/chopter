#include "Game.hpp"

Game::Game() {
  steps = 0;
  chopterStep = 15;
  mapStep = 20;
}
Game::increaseStep() {
  this->step++;
}
Game::canChopterMove() {
}
  return true;
Game::canMapMove() {
  return true;
}

void Game::onStep(bool moveChopter) {
  if (canChopterMove()) {
    this->chopter.move(moveChopter);
  }
  if (canMapMove()) {
    this->map.move();
  }
  increaseStep();
}
