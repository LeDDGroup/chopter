#include "../../visual/Button.hpp"
#include "../Environment.hpp"
#include "../color.hpp"
#include "GameController.hpp"

extern Environment environment;

#define C_SCREEN C_BLACK
#define C_PLAYER C_BLUE
#define C_CEIL C_RED
#define C_FLOOR C_GREEN

static int xoffset;
const int size = 32;
const int height = 15;

void GameController::clearScreen() {
  Button sprite;
  sprite.color = C_SCREEN;
  sprite.rect.x = 0; sprite.rect.y = 0;
  sprite.rect.w = 640; sprite.rect.h = 480;
  sprite.draw();
}

void GameController::drawChopter(const Chopter & chopter) {
  Button sprite;
  sprite.rect.x = chopter.getX() - xoffset; sprite.rect.y = chopter.getY();
  sprite.rect.w = chopter.getWidth(); sprite.rect.h = chopter.getHeight();
  sprite.draw();
}

void GameController::drawColumn(int x, const Hole &hole) {
  Button sprite;
  sprite.rect.w = sprite.rect.h = size;
  sprite.rect.x = x;
  const int y1 = hole.height;
  const int y2 = y1 + hole.size;
  for (int j = 0; j <= y1; j++) {
    sprite.rect.y = j*size;
    sprite.color = C_CEIL;
    sprite.draw();
  }
  for (int j = y2+1; j < height; j++) {
    sprite.rect.y = j*size;
    sprite.color = C_FLOOR;
    sprite.draw();
  }
}

void GameController::drawMap(const Map & map) {
  const int length = map.getLength();
  const Hole * field = map.getField();
  for (int i = 0; i < length; i++) {
    drawColumn(i * size - xoffset, field[i]);
    drawColumn((i+length) * size - xoffset, field[i]);
    drawColumn((i-length) * size - xoffset, field[i]);
  }
}

void GameController::draw() {
  const Chopter &chopter = game.getChopter();
  const Map &map = game.getMap();
  xoffset = chopter.getX() - 64;
  clearScreen();
  drawMap(map);
  drawChopter(chopter);
  environment.renderer.Present();
}
