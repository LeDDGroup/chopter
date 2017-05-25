#include "Score.hpp"
#include <fstream>

using namespace std;

Score::Score () {
  currentScore = 0;
}

void Score::increaseScore() {
  currentScore++;
};

void Score::saveScore() {
  ofstream scoreFile;
  scoreFile.open("src/data/score");
  scoreFile << currentScore << endl;
  scoreFile.close();
};

void Score::loadScore() {

};
