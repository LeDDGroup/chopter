#include "Environment.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Environment::Environment() {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  font = TTF_OpenFont("resource/Cantarell-Regular.otf", 28);
  window = SDL_CreateWindow("Chopter",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
  surface = SDL_GetWindowSurface(window);
}

Environment::~Environment() {
  if (window) {
    SDL_DestroyWindow(window);
  }
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
}
