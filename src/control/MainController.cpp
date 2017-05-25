#include "MainController.hpp"
#include "Event.hpp"

MainController::MainController(Logic * logic)
  : Controller(logic) {};

void MainController::loop() {
  Event event;
  while(event.waitForStepTime()) {
    // TODO implement draw and button clicks
  }
}
