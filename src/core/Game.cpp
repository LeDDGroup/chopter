#include "Game.hpp"

Game::Game() {
  steps = 0;
  chopterStep = 15;
  mapStep = 20;
}
void Game::increaseStep() {
  this->steps++;
}
bool Game::canChopterMove() const {
  return true;
}
bool Game::canMapMove() const {
  return true;
}

void Game::onStep(bool moveChopter) {
  if (this->canChopterMove()) {
    this->chopter.move(moveChopter);
  }
  if (this->canMapMove()) {
    this->map.move();
  }
  this->increaseStep();
}
