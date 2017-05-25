#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <SDL2/SDL.h>
#include "Controller.hpp"
#include "Event.hpp"
#include "../core/Game.hpp"

class GameController: public Controller {
  SDL_Window * window;
  SDL_Surface * screenSurface;
  Game game;
  void clearScreen();
  void drawChopter(const Chopter & chopter);
  void drawColumn(int x, const Hole &hole);
  void drawMap(const Map & map);
public:
  void draw();
  void init();
  void loop();
  void quit();
};


#endif
