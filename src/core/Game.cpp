#include "Game.hpp"

Game::Game() {
  steps = 0;
  verticalChopterSteps = 15;
  horizontalChopterSteps = 20;
}

void Game::increaseStep() {
  steps++;
}

void Game::moveChopter(bool fuel) {
  if (steps % verticalChopterSteps == 0) {
    chopter.move(fuel);
  }
  if (steps % horizontalChopterSteps == 0) {
    map.move();
  }
}

void Game::checkColition() {
}

void Game::removeBlocks() {
}

void Game::onStep(bool fuel) {
  moveChopter(fuel);
  checkColition();
  removeBlocks();
  increaseStep();
}

const Chopter & Game::getChopter() const {
  return chopter;
}
