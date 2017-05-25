#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include "Controller.hpp"
#include "../core/Game.hpp"
#include "../core/Chopter.hpp"
#include "../core/Map.hpp"

#define C_BLACK 0x00000000
#define C_WHITE 0xFFFFFFFF
#define C_RED   0xFFFF0000
#define C_GREEN 0xFF00FF00
#define C_BLUE  0xFF0000FF

#define C_SCREEN C_BLACK
#define C_PLAYER C_BLUE
#define C_CEIL C_RED
#define C_FLOOR C_GREEN

extern SDL_Window * window;
extern SDL_Surface * screenSurface;
extern Game game;

static SDL_Rect rect;
static int xoffset;
const int size = 32;
const int height = 15;

void Controller::clearScreen() {
  rect.x = 0; rect.y = 0;
  rect.w = 640; rect.h = 480;
  SDL_FillRect(screenSurface, &rect, C_SCREEN);
}

void Controller::drawChopter(const Chopter & chopter) {
  rect.x = chopter.getX() - xoffset; rect.y = chopter.getY();
  rect.w = chopter.getWidth(); rect.h = chopter.getHeight();
  SDL_FillRect(screenSurface, &rect, C_PLAYER);
}

void Controller::drawColumn(int x, const Hole &hole) {
  rect.x = x;
  const int y1 = hole.height;
  const int y2 = y1 + hole.size;
  for (int j = 0; j <= y1; j++) {
    rect.y = j*size;
    SDL_FillRect(screenSurface, &rect, C_CEIL);
  }
  for (int j = y2+1; j < height; j++) {
    rect.y = j*size;
    SDL_FillRect(screenSurface, &rect, C_FLOOR);
  }
}

void Controller::drawMap(const Map & map) {
  rect.w = size; rect.h = size;
  const int length = map.getLength();
  const Hole * field = map.getField();
  for (int i = 0; i < length; i++) {
    drawColumn(i * size - xoffset, field[i]);
    drawColumn((i+length) * size - xoffset, field[i]);
  }
}

void Controller::draw() {
  const Chopter &chopter = game.getChopter();
  const Map &map = game.getMap();
  xoffset = chopter.getX();
  clearScreen();
  drawMap(map);
  drawChopter(chopter);
  SDL_UpdateWindowSurface(window);
}
