#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include "Controller.hpp"
#include "Event.hpp"
#include "../visual/Button.hpp"

class MainController: public Controller, private Event {
  Button btnPlay;
  void draw();
public:
  MainController(Logic * logic);
  void loop();
};

#endif
