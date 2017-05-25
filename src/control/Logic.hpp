#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SDL2/SDL.h>
#include "Controller.hpp"

class Controller;

class Logic {
public:
  enum State { Quit, MainMenu, PlayGame };
private:
  static bool hasError;
  SDL_Window * window;
  SDL_Surface * screenSurface;
  void runMainMenuController();
  void runGameController();
  State state;
public:
  static void throwError() { hasError = true; }
  void init();
  void run();
  void quit();
  void manage(Controller &controller);
  void nextState(State signal);
  SDL_Window * getWindow() { return window; }
  SDL_Surface * getScreenSurface() { return screenSurface; }
};

#endif
