#include "control/GameController.hpp"

int main() {
  GameController controller;
  controller.init();
  controller.loop();
  controller.quit();
  return 0;
}
