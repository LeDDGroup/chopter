#pragma once

class Event {
  bool quit;
  bool checkEvents();
public:
  Event();
  bool waitForStepTime();
  bool checkForButtonDown() const;
};
