#include "control/Logic.hpp"
#include "control/GameController.hpp"

int main() {
  Logic logic;
  logic.init();
  logic.run();
  logic.quit();
  return 0;
}
