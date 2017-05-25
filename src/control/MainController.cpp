#include "Logic.hpp"
#include "MainController.hpp"
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
  draw();
  while(checkEvents()) {}
}

static SDL_Rect rect;

void MainController::draw() {
  rect.x = 0; rect.y = 0;
  rect.w = 640; rect.h = 480;
  SDL_FillRect(logic->getScreenSurface(), &rect, C_SCREEN);
  btnPlay.draw(logic->getScreenSurface());
  SDL_UpdateWindowSurface(logic->getWindow());
}

bool MainController::processEvent(const SDL_Event & event) {
  if (!Event::processEvent(event)) {
    logic->nextState(Logic::Quit);
    return false;
  }
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    // TODO check for actual click on the button
    logic->nextState(Logic::PlayGame);
    quit = true;
    return false;
  }
  return true;
}
