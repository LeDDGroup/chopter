#ifndef EVENT_HPP
#define EVENT_HPP

#include <SDL2/SDL_events.h>

class Event {
protected:
  bool quit;
  Uint32 prevTime;
  Uint32 timeout;
  bool isTime();
  void resetTime();
  virtual bool processEvent(const SDL_Event &event);
public:
  Event();
  bool waitForStepTime();
  bool checkEvents();
};

#endif
