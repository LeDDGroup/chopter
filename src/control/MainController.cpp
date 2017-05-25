#include "MainController.hpp"
#include "Event.hpp"
#include "color.hpp"

#define C_SCREEN C_BLACK

MainController::MainController(Logic * logic)
  : Controller(logic) {
  btnPlay.rect.x = 256;
  btnPlay.rect.y = 64;
  btnPlay.rect.w = 128;
  btnPlay.rect.h = 48;
  btnPlay.color = C_BLUE;
};

void MainController::loop() {
  Event event;
  while(event.waitForStepTime()) {
    // TODO implement draw and button clicks
  }
}
