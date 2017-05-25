#include "Logic.hpp"
#include "Controller.hpp"
#include "MainController.hpp"

void Logic::init() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Chopter",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            SDL_WINDOW_SHOWN);
  screenSurface = SDL_GetWindowSurface(window);
}

void Logic::quit() {
  SDL_Quit();
}

void Logic::manage(Controller &controller) {
  controller.init();
  controller.loop();
}

void Logic::sign(Signal signal) {
  switch (signal) {
  case PlayGame:
    runGameController();
    break;
  }
}

void Logic::run() {
  runGameController();
}

void Logic::runGameController() {
  MainController controller(this);
  manage(controller);
}
