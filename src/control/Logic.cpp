#include "Logic.hpp"
#include "Controller.hpp"

void Logic::init() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Chopter",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
  screenSurface = SDL_GetWindowSurface(window);
}

void Logic::quit() {
  SDL_Quit();
}
