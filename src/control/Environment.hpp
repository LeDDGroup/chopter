#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2pp/SDL2pp.hh>

class Environment {
public:
  SDL2pp::SDL sdl;
  SDL_Window * window;
  SDL_Surface * surface;
  TTF_Font *font;
  Environment();
  ~Environment();
};
