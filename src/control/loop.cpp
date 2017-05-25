#include <SDL2/SDL_events.h>
#include "Controller.hpp"
#include "Event.hpp"

void Controller::loop() {
  Event event;
  while(event.waitForStepTime()) {
    if (!game.hasFinished()) {
      const bool action = event.checkForButtonDown();
      game.onStep(action);
      draw();
    }
  }
}
