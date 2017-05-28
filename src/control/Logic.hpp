#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "Controller.hpp"

class Controller;

class Logic {
public:
  enum State { Quit, MainMenu, PlayGame };
private:
  void runMainMenuController();
  void runGameController();
  State state;
public:
  void init();
  void run();
  void quit();
  void manage(Controller &controller);
  void nextState(State signal);
};

#endif
