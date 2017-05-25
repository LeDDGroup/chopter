#include "../Logic.hpp"
#include "../color.hpp"
#include "../../core/Point.hpp"
#include "MainController.hpp"

#define C_SCREEN C_BLACK

MainController::MainController(Logic * logic)
  : Controller(logic) {
  btnPlay.text = "Play";
  btnPlay.rect.x = 256; btnPlay.rect.y = 64;
  btnPlay.rect.w = 128; btnPlay.rect.h = 48;
  btnPlay.color = C_BLUE;
  btnQuit.text = "Quit";
  btnQuit.rect.x = 256; btnQuit.rect.y = 480-64-48;
  btnQuit.rect.w = 128; btnQuit.rect.h = 48;
  btnQuit.color = C_RED;
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
  btnQuit.draw(logic->getScreenSurface());
  SDL_UpdateWindowSurface(logic->getWindow());
}

bool MainController::processEvent(const SDL_Event & event) {
  if (!Event::processEvent(event)) {
    logic->nextState(Logic::Quit);
    return false;
  }
  if (event.type == SDL_MOUSEBUTTONDOWN) {
    Point<int> mouse;
    SDL_GetMouseState(&mouse.x, &mouse.y);
    if (btnPlay.checkClick(mouse)) {
      logic->nextState(Logic::PlayGame);
      quit = true;
      return false;
    }
    if (btnQuit.checkClick(mouse)) {
      logic->nextState(Logic::Quit);
      quit = true;
      return false;
    }
  }
  return true;
}
