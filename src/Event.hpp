#pragma once

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
