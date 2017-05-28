#include "Logic.hpp"
#include "Controller.hpp"
#include "controllers/MainController.hpp"
#include "controllers/GameController.hpp"
#include "../visual/Button.hpp"
#include "../visual/Label.hpp"
#include "Environment.hpp"

extern Environment environment;

bool Logic::hasError;

void Logic::init() {
  hasError = false;
  window = SDL_CreateWindow("Chopter",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
  screenSurface = SDL_GetWindowSurface(window);
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
  if (hasError) {
    nextState(Quit);
  }
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
  if (hasError) {
    printf("SDL Error: %s\n", SDL_GetError());
    printf("SDL_ttf Error: %s\n", TTF_GetError());
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
