#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/SDLTTF.hh>
#include <SDL2pp/Font.hh>

class Environment {
public:
  SDL2pp::SDL sdl;
  SDL2pp::SDLTTF ttf;
  SDL2pp::Font font;
  SDL_Window * window;
  SDL_Surface * surface;
  Environment();
  ~Environment();
};
