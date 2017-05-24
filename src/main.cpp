#include <cstdio>
#include <SDL2/SDL.h>
#include "core/Game.hpp"

SDL_Window *window;
SDL_Event event;
Game game;

bool waitForStepTime();
bool checkForButtonDown();

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

void loop() {
  while(waitForStepTime()) {
    const bool action = checkForButtonDown();
    game.onStep(action);
  }
}

bool waitForStepTime() {
  return false;
}
bool checkForButtonDown() {
  return false;
}
