#include <cstdio>
#include <SDL2/SDL.h>

const SDL_Window * window;
int main() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Hello World",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
  SDL_Delay(1000);
  SDL_Quit();
  return 0;
}
