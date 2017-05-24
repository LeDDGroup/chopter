#include <SDL2/SDL_events.h>
#include "core/Game.hpp"

extern Game game;

bool waitForStepTime();
bool checkForButtonDown();
void draw();

SDL_Event event;

void loop() {
  while(waitForStepTime()) {
    const bool action = checkForButtonDown();
    game.onStep(action);
    draw();
  }
}

bool waitForStepTime() {
  return false;
}
bool checkForButtonDown() {
  return false;
}
