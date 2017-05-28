#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <SDL2/SDL_events.h>
#include "../../visual/Label.hpp"
#include "../../visual/TextButton.hpp"
#include "../Controller.hpp"
#include "../Event.hpp"

class MainController: public Controller, private Event {
  const int componentWidth;
  const int componentHeight;
  const SDL2pp::Point roomSize;
  const int centerX;
  TextButton btnPlay;
  TextButton btnQuit;
  Label labelScore;
  void draw();
  bool processEvent(const SDL_Event & event);
  char highScoreText[100];
public:
  MainController(Logic * logic);
  void loop();
};

#endif
