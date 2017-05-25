#include <SDL2/SDL_events.h>
#include "core/Game.hpp"
#include "Event.hpp"

extern Game game;

void draw();

void loop() {
  Event event;
  while(event.waitForStepTime()) {
    if (!game.hasFinished()) {
      const bool action = event.checkForButtonDown();
      game.onStep(action);
      draw();
    }
  }
}
