#include "GameController.hpp"
#include "../color.hpp"
#include "../Environment.hpp"

extern Environment environment;

GameController::GameController(Logic * logic)
  : Controller(logic), hasPressedKey(false), started(false) {};

void GameController::loop() {
  draw();
  while(waitForStepTime()) {
    if (started) {
      if (!game.hasFinished()) {
        bool action = checkForButtonDown();
        game.onStep(action);
        draw();
      } else {
        logic->nextState(Logic::MainMenu);
        break;
      }
    }
    hasPressedKey = false;
  }
}

bool GameController::processEvent(const SDL_Event & event) {
  if (!Event::processEvent(event)) {
    logic->nextState(Logic::Quit);
    return false;
  }
  switch (event.type) {
  case SDL_KEYDOWN:
    started = true;
    if (event.key.keysym.sym == SDLK_UP) {
      hasPressedKey = true;
    }
    break;
  }
  return true;
}

bool GameController::checkForButtonDown() const {
  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
  return currentKeyStates[SDL_SCANCODE_UP] || hasPressedKey;
}


#define C_SCREEN C_BLACK
#define C_PLAYER C_BLUE
#define C_CEIL C_RED
#define C_FLOOR C_GREEN

static SDL_Rect rect;
static int xoffset;
const int size = 32;
const int height = 15;

void GameController::clearScreen() {
  rect.x = 0; rect.y = 0;
  rect.w = 640; rect.h = 480;
  SDL_FillRect(environment.surface, &rect, C_SCREEN);
}

void GameController::drawChopter(const Chopter & chopter) {
  rect.x = chopter.getX() - xoffset; rect.y = chopter.getY();
  rect.w = chopter.getWidth(); rect.h = chopter.getHeight();
  SDL_FillRect(environment.surface, &rect, C_PLAYER);
}

void GameController::drawColumn(int x, const Hole &hole) {
  rect.x = x;
  const int y1 = hole.height;
  const int y2 = y1 + hole.size;
  for (int j = 0; j <= y1; j++) {
    rect.y = j*size;
    SDL_FillRect(environment.surface, &rect, C_CEIL);
  }
  for (int j = y2+1; j < height; j++) {
    rect.y = j*size;
    SDL_FillRect(environment.surface, &rect, C_FLOOR);
  }
}

void GameController::drawMap(const Map & map) {
  rect.w = size; rect.h = size;
  const int length = map.getLength();
  const Hole * field = map.getField();
  for (int i = 0; i < length; i++) {
    drawColumn(i * size - xoffset, field[i]);
    drawColumn((i+length) * size - xoffset, field[i]);
    drawColumn((i-length) * size - xoffset, field[i]);
  }
}

void GameController::draw() {
  const Chopter &chopter = game.getChopter();
  const Map &map = game.getMap();
  xoffset = chopter.getX() - 64;
  clearScreen();
  drawMap(map);
  drawChopter(chopter);
  SDL_UpdateWindowSurface(environment.window);
}
