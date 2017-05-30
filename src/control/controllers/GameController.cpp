#include "GameController.hpp"
#include "../Environment.hpp"

extern Environment environment;

GameController::GameController(Logic * logic)
  : Controller(logic),
    hasPressedKey(false),
    started(false),
    chopter("resource/chopter.png") {};

void GameController::loop() {
  draw();
  while(waitForStepTime()) {
    if (started) {
      if (!game.hasFinished()) {
        bool action = checkForButtonDown();
        game.onStep(action);
        draw();
      } else {
        logic->nextState(Logic::MainMenu);
        break;
      }
    }
    hasPressedKey = false;
  }
}

bool GameController::processEvent(const SDL_Event & event) {
  if (!Event::processEvent(event)) {
    logic->nextState(Logic::Quit);
    return false;
  }
  switch (event.type) {
  case SDL_KEYDOWN:
    started = true;
    if (event.key.keysym.sym == SDLK_UP) {
      hasPressedKey = true;
    }
    break;
  }
  return true;
}

bool GameController::checkForButtonDown() const {
  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
  return currentKeyStates[SDL_SCANCODE_UP] || hasPressedKey;
}
