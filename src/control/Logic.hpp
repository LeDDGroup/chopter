#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SDL2/SDL.h>

class Controller;

class Logic {
  SDL_Window * window;
  SDL_Surface * screenSurface;
public:
  void init();
  void quit();
};

#endif
