#include <SDL2/SDL_events.h>
#include "core/Game.hpp"

extern Game game;

bool waitForStepTime();
bool checkForButtonDown();

SDL_Event event;

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
