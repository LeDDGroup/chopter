#include "../../core/Point.hpp"
#include "../Environment.hpp"
#include "../Logic.hpp"
#include "../color.hpp"
#include "MainController.hpp"

extern Environment environment;

#define C_SCREEN C_BLACK

MainController::MainController(Logic * logic)
  : Controller(logic) {
  btnPlay.rect.x = 256; btnPlay.rect.y = 64;
  btnPlay.rect.w = 128; btnPlay.rect.h = 48;
  btnPlay.color = C_BLUE;
  labelPlay.setText("Play");
  labelPlay.rect = btnPlay.rect;
  btnQuit.rect.x = 256; btnQuit.rect.y = 480-64-48;
  btnQuit.rect.w = 128; btnQuit.rect.h = 48;
  btnQuit.color = C_RED;
  labelQuit.setText("Quit");
  labelQuit.rect = btnQuit.rect;
};

void MainController::loop() {
  draw();
  while(checkEvents()) {
    draw();
  }
}

static SDL_Rect rect;

void MainController::draw() {
  rect.x = 0; rect.y = 0;
  rect.w = 640; rect.h = 480;
  SDL_FillRect(environment.surface, &rect, C_SCREEN);
  btnPlay.draw();
  btnQuit.draw();
  labelPlay.draw();
  labelQuit.draw();
  environment.renderer.Present();
}

bool MainController::processEvent(const SDL_Event & event) {
  if (!Event::processEvent(event)) {
    logic->nextState(Logic::Quit);
    return false;
  }
  if (event.type == SDL_MOUSEMOTION) {
    Point<int> mouse;
    SDL_GetMouseState(&mouse.x, &mouse.y);
    if (btnPlay.checkClick(mouse)) {
      btnPlay.selected = true;
    } else {
      btnPlay.selected = false;
    }
    if (btnQuit.checkClick(mouse)) {
      btnQuit.selected = true;
    } else {
      btnQuit.selected = false;
    }
  } else if (event.type == SDL_MOUSEBUTTONDOWN) {
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
