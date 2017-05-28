#include "../visual/Button.hpp"
#include "../visual/Label.hpp"
#include "Controller.hpp"
#include "Environment.hpp"
#include "Logic.hpp"
#include "controllers/GameController.hpp"
#include "controllers/MainController.hpp"
#include <fstream>

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

void Logic::writeScore(int score) {
  std::ofstream fout("score.txt");
  fout << score << std::endl;
}

int Logic::readScore() {
  std::ifstream fin("score.txt");
  int score;
  fin >> score;
  return score;
}
