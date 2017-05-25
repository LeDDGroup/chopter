#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Logic;

class Controller {
protected:
  Logic * logic;
public:
  Controller(Logic * logic);
  virtual void init();
  virtual void loop() = 0;
};

#endif
