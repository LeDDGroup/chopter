#include <SDL2/SDL_events.h>
#include "GameController.hpp"
#include "Event.hpp"

void GameController::loop() {
  Event event;
  while(event.waitForStepTime()) {
    if (!game.hasFinished()) {
      const bool action = event.checkForButtonDown();
      game.onStep(action);
      draw();
    }
  }
}
