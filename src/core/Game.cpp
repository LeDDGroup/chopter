#include "Game.hpp"
#include "Map.hpp"

Game::Game() {
  blockWidth = 32;
  score = 0;
}

void Game::moveChopter(bool fuel) {
  chopter.move(fuel);

  // position.y = ((int)position.y + 480) % 480; TODO
  chopter.position.x = (int)chopter.position.x % (blockWidth * map.getLength());
}

bool Game::checkColition() {
  int xChopter = chopter.getX();
  int yChopter = chopter.getY();
  const Hole * field = map.getField();
  int chopterPosition = map.pxToBlock(xChopter, blockWidth) % map.getLength();
  int otherBlock = map.pxToBlock(xChopter + chopter.getWidth() - 1, blockWidth) % map.getLength();
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
  if (!checkColition()) finish();
  updateBlocks();
  score++;
}

void Game::finish() {
  done = true;
}
