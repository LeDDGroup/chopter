#include "Game.hpp"

Game::Game() {
  steps = 0;
  verticalChopterSteps = 1;
  horizontalChopterSteps = 20;
  blockWidth = 32;
}

void Game::increaseStep() {
  steps++;
}

void Game::moveChopter(bool fuel) {
  if (steps % verticalChopterSteps == 0) {
    chopter.move(fuel);
  }
}

void Game::checkColition() {
}

void Game::updateBlocks() {
  int position = map.pxToBlock(chopter.getX(), blockWidth);
  map.onStep(position);
}

void Game::onStep(bool fuel) {
  moveChopter(fuel);
  checkColition();
  updateBlocks();
  increaseStep();
}

void Game::finish() {
  done = true;
}
