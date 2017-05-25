#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <SDL2/SDL.h>
#include "Logic.hpp"
#include "Controller.hpp"
#include "Event.hpp"
#include "../core/Game.hpp"

class GameController: public Controller {
  Game game;
  void clearScreen();
  void drawChopter(const Chopter & chopter);
  void drawColumn(int x, const Hole &hole);
  void drawMap(const Map & map);
public:
  GameController(Logic * logic);
  void draw();
  void loop();
};


#endif
