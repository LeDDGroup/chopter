#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <SDL2/SDL.h>
#include "Event.hpp"
#include "../core/Game.hpp"

class GameController {
  SDL_Window * window;
  SDL_Surface * screenSurface;
  Game game;
  void clearScreen();
  void drawChopter(const Chopter & chopter);
  void drawColumn(int x, const Hole &hole);
  void drawMap(const Map & map);
  void draw();
public:
  void init();
  void loop();
  void quit();
};


#endif
