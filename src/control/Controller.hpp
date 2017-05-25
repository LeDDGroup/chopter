#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Logic;

class Controller {
  Logic * logic;
public:
  Controller(Logic * logic = 0);
  virtual void init() = 0;
  virtual void draw() = 0;
  virtual void loop() = 0;
};

#endif
