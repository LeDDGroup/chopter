#include "score.hpp"
#include <fstream>

void writeScore(int score) {
  std::ofstream fout("score.txt");
  fout << score << std::endl;
}

int readScore() {
  std::ifstream fin("score.txt");
  int score;
  fin >> score;
  return score;
}
