#include "Score.hpp"
#include <cstdio>

using namespace std;

Score::Score () {
  currentScore = 0;
}

void Score::increaseScore() {
  currentScore++;
};

void Score::saveScore() {
  freopen ("src/data/score","a",stdout);
  printf ("%i\n", currentScore);
  fclose (stdout);
};

void Score::loadScore() {

};
