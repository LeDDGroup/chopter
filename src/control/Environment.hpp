#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Environment {
public:
  SDL_Window * window;
  SDL_Surface * surface;
  TTF_Font *font;
  Environment();
  ~Environment();
};
