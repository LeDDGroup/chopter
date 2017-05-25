class Score {
  int currentScore;
public:
  Score();
  int getCurrentScore() const {return currentScore};
  void increaseScore();
  void saveScore();
  void loadScore();
};
