#include <cstdio>
#include <SDL2/SDL.h>
#include "core/Game.hpp"

void loop();

SDL_Window * window;
Game game;

void init() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Chopter",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
}
void quit() {
  SDL_Quit();
}

int main() {
  init();
  loop();
  quit();
  return 0;
}
