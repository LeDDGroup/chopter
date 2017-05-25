#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include "Controller.hpp"
#include "../visual/Button.hpp"

class MainController: public Controller {
  Button btnPlay;
  void draw();
public:
  MainController(Logic * logic);
  void loop();
};

#endif
