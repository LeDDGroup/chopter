#include "control/Controller.hpp"

int main() {
  Controller controller;
  controller.init();
  controller.loop();
  controller.quit();
  return 0;
}
