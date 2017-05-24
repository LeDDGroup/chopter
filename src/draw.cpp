#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include "core/Game.hpp"

#define C_BLACK 0x00000000
#define C_WHITE 0xFFFFFFFF

extern SDL_Window * window;
extern SDL_Surface * screenSurface;
extern Game game;

static SDL_Rect rect;

void clearScreen() {
  rect.x = 0; rect.y = 0;
  rect.w = 640; rect.h = 480;
  SDL_FillRect(screenSurface, &rect, C_BLACK);
}

void drawChopter(const Chopter & chopter) {
  rect.x = chopter.getX(); rect.y = chopter.getY();
  rect.w = 32; rect.h = 32;
  SDL_FillRect(screenSurface, &rect, C_WHITE);
}

void draw() {
  const Chopter &chopter = game.getChopter();
  clearScreen();
  drawChopter(chopter);
  SDL_UpdateWindowSurface(window);
}
