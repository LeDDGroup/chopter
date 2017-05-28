#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/SDLTTF.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Font.hh>

class Environment {
  static const char * default_window_title;
  static const int default_window_position_x, default_window_position_y;
  static const int default_window_size_x, default_window_size_y;
  static const int default_window_state;
public:
  SDL2pp::SDL sdl;
  SDL2pp::SDLTTF ttf;
  SDL2pp::Font font;
  SDL2pp::Window window;
  SDL2pp::Renderer renderer;
  SDL_Surface * surface;
  Environment();
  ~Environment();
};

#endif
