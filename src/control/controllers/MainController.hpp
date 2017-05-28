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
  Label labelScore;
  void draw();
  bool processEvent(const SDL_Event & event);
  char highScoreText[100];
public:
  MainController(Logic * logic);
  void loop();
};

#endif
