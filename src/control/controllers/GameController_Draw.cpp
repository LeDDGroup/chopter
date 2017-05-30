#include "../../visual/Button.hpp"
#include "../../visual/Label.hpp"
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
  sprite.setColor(C_SCREEN);
  sprite = SDL2pp::Rect(SDL2pp::Point(0, 0),
                        environment.window.GetSize());
  sprite.draw();
}

void GameController::drawChopter(const Chopter & chopter) {
  Button sprite;
  sprite.setColor(C_PLAYER);
  sprite = SDL2pp::Rect(chopter.getX() - xoffset, chopter.getY(),
                        chopter.getWidth(), chopter.getHeight());
  sprite.draw();
}

void GameController::drawColumn(int x, const Hole &hole) {
  Button sprite;
  sprite.w = sprite.h = size;
  sprite.x = x;
  const int y1 = hole.height;
  const int y2 = y1 + hole.size;
  sprite.setColor(C_CEIL);
  for (int j = 0; j <= y1; j++) {
    sprite.y = j*size;
    sprite.draw();
  }
  sprite.setColor(C_FLOOR);
  for (int j = y2+1; j < height; j++) {
    sprite.y = j*size;
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

void GameController::drawScore() {
  Label label;
  sprintf(scoreText, "Score: %i", getScore());
  label.setText(scoreText);
  label.setRect(SDL2pp::Rect(0, 0,
                             128, 64));
  label.setHAlign(Left);
  label.setVAlign(Top);
  label.draw();
}

void GameController::draw() {
  const Chopter &chopter = game.getChopter();
  const Map &map = game.getMap();
  xoffset = chopter.getX() - 64;
  clearScreen();
  drawMap(map);
  drawScore();
  drawChopter(chopter);
  environment.renderer.Present();
}
