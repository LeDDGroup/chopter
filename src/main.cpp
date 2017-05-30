#include "control/Logic.hpp"
#include "control/Environment.hpp"
#include "Config.h"

Environment environment;

int main() {
  Logic logic;
  logic.init();
  logic.run();
  logic.quit();
  return 0;
}
