#include "Environment.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Environment::Environment() {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  font = TTF_OpenFont("resource/Cantarell-Regular.otf", 28 );
}

Environment::~Environment() {
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
}
