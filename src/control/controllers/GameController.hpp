#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "../../core/Game.hpp"
#include "../Controller.hpp"
#include "../Event.hpp"
#include "../Logic.hpp"

class GameController: public Controller, private Event {
  char scoreText[100];
  Game game;
  bool hasPressedKey;
  bool started;
  bool checkForButtonDown() const;
  void clearScreen();
  void drawChopter(const Chopter & chopter);
  void drawColumn(int x, const Hole &hole);
  void drawMap(const Map & map);
  bool processEvent(const SDL_Event & event);
  void drawScore();
public:
  GameController(Logic * logic);
  void draw();
  void loop();
  int getScore() const { return game.getScore(); };
};


#endif
