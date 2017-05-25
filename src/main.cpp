#include "control/Logic.hpp"
#include "control/GameController.hpp"

int main() {
  Logic logic;
  GameController controller(&logic);
  logic.init();
  logic.manage(controller);
  logic.quit();
  return 0;
}
