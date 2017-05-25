#include "Game.hpp"
#include "Map.hpp"

Game::Game() {
  blockWidth = 32;
}

void Game::moveChopter(bool fuel) {
  chopter.move(fuel);
}

bool Game::checkColition() {
  int xChopter = chopter.getX();
  int yChopter = chopter.getY();
  const Hole * field = map.getField();
  int chopterPosition = map.pxToBlock(xChopter, blockWidth);
  int otherBlock = map.pxToBlock(xChopter + chopter.getWidth() - 1, blockWidth);
  if(field[chopterPosition].height * blockWidth >= yChopter - blockWidth ) {
    return false;
  }
  if((field[chopterPosition].height + field[chopterPosition].size) * blockWidth <= yChopter) {
    return false;
  }
  if(field[otherBlock].height * blockWidth >= yChopter - blockWidth) {
    return false;
  }
  if((field[otherBlock].height + field[otherBlock].size) * blockWidth <= yChopter) {
    return false;
  }
  return true;
}

void Game::updateBlocks() {
  int position = map.pxToBlock(chopter.getX(), blockWidth);
  map.onStep(position);
}

void Game::onStep(bool fuel) {
  moveChopter(fuel);
  if (!checkColition()) chopter.invertSpeed();
  updateBlocks();
}

void Game::finish() {
  done = true;
}
