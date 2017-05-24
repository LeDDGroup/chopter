#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include "core/Game.hpp"
#include "core/Chopter.hpp"
#include "core/Map.hpp"

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

void clearScreen() {
  rect.x = 0; rect.y = 0;
  rect.w = 640; rect.h = 480;
  SDL_FillRect(screenSurface, &rect, C_SCREEN);
}

void drawChopter(const Chopter & chopter) {
  rect.x = chopter.getX(); rect.y = chopter.getY();
  rect.w = chopter.getWidth(); rect.h = chopter.getHeight();
  SDL_FillRect(screenSurface, &rect, C_PLAYER);
}

void drawMap(const Map & map) {
  const int size = 32;
  rect.w = size; rect.h = size;
  const int base = 480;
  const int height = 15;
  const int length = map.getLength();
  const Hole * field = map.getField();
  for (int i = 0; i < length; i++) {
    rect.x = i * size;
    const int y1 = field[i].height;
    const int y2 = y1 + field[i].size;
    for (int j = 0; j <= y1; j++) {
      rect.y = j*size;
      SDL_FillRect(screenSurface, &rect, C_CEIL);
    }
    for (int j = y2+1; j < height; j++) {
      rect.y = j*size;
      SDL_FillRect(screenSurface, &rect, C_FLOOR);
    }
  }
}

void draw() {
  const Chopter &chopter = game.getChopter();
  const Map &map = game.getMap();
  clearScreen();
  drawMap(map);
  drawChopter(chopter);
  SDL_UpdateWindowSurface(window);
}
