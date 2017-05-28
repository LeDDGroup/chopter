#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <SDL2/SDL_events.h>
#include "../../visual/Button.hpp"
#include "../../visual/Label.hpp"
#include "../Controller.hpp"
#include "../Event.hpp"

class MainController: public Controller, private Event {
  Button btnPlay;
  Label labelPlay;
  Button btnQuit;
  Label labelQuit;
  void draw();
  bool processEvent(const SDL_Event & event);
public:
  MainController(Logic * logic);
  void loop();
};

#endif
