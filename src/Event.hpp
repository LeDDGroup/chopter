#pragma once

class Event {
public:
  bool waitForStepTime();
  bool checkForButtonDown() const;
};
