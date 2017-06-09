#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "Controller.hpp"
#include "Config.hpp"

class Controller;

class Logic {
public:
  enum State { Quit, MainMenu, PlayGame };
private:
  void runMainMenuController();
  void runGameController();
  State state;
public:
  Logic();
  void init();
  void run();
  void quit();
  void manage(Controller &controller);
  void nextState(State signal);
  Config config;
};

#endif
