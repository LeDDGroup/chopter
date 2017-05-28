#include "control/Logic.hpp"
#include "control/Environment.hpp"

Environment environment;

int main() {
  Logic logic;
  logic.init();
  logic.run();
  logic.quit();
  return 0;
}
