#include "Game.hpp"

Game::Game() {
  blockWidth = 32;
}

void Game::moveChopter(bool fuel) {
  chopter.move(fuel);
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
}

void Game::finish() {
  done = true;
}
