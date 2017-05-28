#include "Logic.hpp"
#include "Controller.hpp"
#include "controllers/MainController.hpp"
#include "controllers/GameController.hpp"
#include "../visual/Button.hpp"
#include "../visual/Label.hpp"
#include "Environment.hpp"

extern Environment environment;

void Logic::init() {
  state = MainMenu;
}

void Logic::quit() {
}

void Logic::manage(Controller &controller) {
  controller.init();
  controller.loop();
}

void Logic::nextState(State signal) {
  state = signal;
}

void Logic::run() {
  while(state != Quit) {
    switch (state) {
    case MainMenu:
      runMainMenuController();
      break;
    case PlayGame:
      runGameController();
      break;
    default:
      state = Quit;
      break;
    }
  }
}

void Logic::runMainMenuController() {
  MainController controller(this);
  manage(controller);
}

void Logic::runGameController() {
  GameController controller(this);
  manage(controller);
}
