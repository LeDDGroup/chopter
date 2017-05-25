#include "GameController.hpp"

void GameController::init() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Chopter",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
  screenSurface = SDL_GetWindowSurface(window);
}

void GameController::quit() {
  SDL_Quit();
}
