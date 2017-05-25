#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <SDL2/SDL_events.h>
#include "Controller.hpp"
#include "Event.hpp"
#include "../visual/Button.hpp"

class MainController: public Controller, private Event {
  Button btnPlay;
  void draw();
  bool processEvent(const SDL_Event & event);
public:
  MainController(Logic * logic);
  void loop();
};

#endif
