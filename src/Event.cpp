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
  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
  return currentKeyStates[SDL_SCANCODE_UP];
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
