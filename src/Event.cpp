#include <SDL2/SDL_events.h>
#include "Event.hpp"

Event::Event() {
  quit = false;
}

bool Event::waitForStepTime() {
  while(checkEvents()) {}
  return !quit;
}

bool Event::checkForButtonDown() const {
  return false;
}

bool Event::checkEvents() {
  SDL_Event event;
  while (!quit && SDL_PollEvent(&event) != 0) {
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
  }
  return !quit;
}
