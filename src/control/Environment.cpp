#include "Config.h"
#include "Environment.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>

const char * Environment::default_window_title = "Chopter";
const int Environment::default_window_position_x = SDL_WINDOWPOS_UNDEFINED;
const int Environment::default_window_position_y = SDL_WINDOWPOS_UNDEFINED;
const int Environment::default_window_size_x = 640;
const int Environment::default_window_size_y = 480;
const int Environment::default_window_state = SDL_WINDOW_SHOWN;

Environment::Environment()
  : sdl(SDL_INIT_VIDEO),
    ttf(),
    font("resource/Cantarell-Regular.otf", 28),
    window(default_window_title,
           default_window_position_x, default_window_position_y,
           default_window_size_x, default_window_size_y,
           default_window_state),
    renderer(window, -1, SDL_RENDERER_ACCELERATED) {
  char title[30];
  sprintf(title, "Chopter v%s", CHOPTER_VERSION);
  window.SetTitle(title);
}

Environment::~Environment() {
}
