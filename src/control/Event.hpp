#ifndef EVENT_HPP
#define EVENT_HPP

#include <SDL2/SDL_events.h>

class Event {
protected:
  bool quit;
  bool hasPressedKey;
  Uint32 prevTime;
  Uint32 timeout;
  bool isTime();
  void resetTime();
public:
  Event();
  bool waitForStepTime();
  bool checkForButtonDown() const;
  bool checkEvents();
};

#endif
