#include "GameController.hpp"
#include "Event.hpp"

GameController::GameController(Logic * logic)
  : Controller(logic) {};

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
