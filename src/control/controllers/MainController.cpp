#include "../../core/Point.hpp"
#include "../Environment.hpp"
#include "../Logic.hpp"
#include "../color.hpp"
#include "MainController.hpp"
#include "../score.hpp"
#include <cstdlib>
#include <cstdio>
#include <SDL2pp/Rect.hh>
#include <SDL2pp/Point.hh>

extern Environment environment;

#define C_SCREEN C_BLACK

MainController::MainController(Logic * logic)
  : Controller(logic),
    componentWidth(256), componentHeight(48),
    roomSize(environment.window.GetSize()),
    centerX((roomSize.x - componentWidth) / 2),
    btnPlay("Play", SDL2pp::Rect(centerX, componentHeight,
                                 componentWidth, componentHeight), C_BLUE),
    btnQuit("Quit", SDL2pp::Rect(centerX, roomSize.y - 2 * componentHeight,
                                 componentWidth, componentHeight), C_RED),
    btnResetHighScore("Reset HighScore", SDL2pp::Rect(centerX, componentHeight * 3,
                                                      componentWidth, componentHeight), C_GREEN),
    screen(SDL2pp::Rect(SDL2pp::Point(0, 0), roomSize), C_SCREEN),
    labelScore("HighScore") {
  labelScore.setRect(SDL2pp::Rect(centerX, 0,
                                  componentWidth, componentHeight));
  labelScore.setHAlign(Center);
  labelScore.setVAlign(Top);
  setHighScore();
};

void MainController::setHighScore() {
  int score = readScore();
  sprintf(highScoreText, "HighScore: %i", score);
  labelScore.setText(highScoreText);
}

void MainController::loop() {
  draw();
  while(checkEvents()) {
    draw();
  }
}

static SDL_Rect rect;

void MainController::draw() {
  screen.draw();
  btnPlay.draw();
  btnQuit.draw();
  btnResetHighScore.draw();
  labelScore.draw();
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
      btnPlay.select();
    } else {
      btnPlay.unselect();
    }
    if (btnQuit.checkClick(mouse)) {
      btnQuit.select();
    } else {
      btnQuit.unselect();
    }
    if (btnResetHighScore.checkClick(mouse)) {
      btnResetHighScore.select();
    } else {
      btnResetHighScore.unselect();
    }
  } else if (event.type == SDL_MOUSEBUTTONDOWN) {
    Point<int> mouse;
    SDL_GetMouseState(&mouse.x, &mouse.y);
    if (btnPlay.checkClick(mouse)) {
      logic->nextState(Logic::PlayGame);
      quit = true;
      return false;
    }
    if (btnResetHighScore.checkClick(mouse)) {
      writeScore(0);
      setHighScore();
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
