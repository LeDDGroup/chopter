#ifndef EVENT_HPP
#define EVENT_HPP

#include <SDL2/SDL_events.h>

class Event {
  bool quit;
  bool hasPressedKey;
  Uint32 prevTime;
  Uint32 timeout;
  bool checkEvents();
  bool isTime();
  void resetTime();
public:
  Event();
  bool waitForStepTime();
  bool checkForButtonDown() const;
};

#endif
