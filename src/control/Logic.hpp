#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SDL2/SDL.h>
#include "Controller.hpp"

class Controller;

class Logic {
  SDL_Window * window;
  SDL_Surface * screenSurface;
public:
  void init();
  void quit();
  SDL_Window * getWindow() { return window; }
  SDL_Surface * getScreenSurface() { return screenSurface; }
};

#endif
