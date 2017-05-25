#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Logic;

class Controller {
protected:
  Logic * logic;
public:
  Controller(Logic * logic = 0);
  virtual void init();
  virtual void loop() = 0;
};

#endif
