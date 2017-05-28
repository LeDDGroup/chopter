#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2pp/Rect.hh>
#include "../core/Point.hpp"

class Button {
public:
  Button();
  bool selected;
  SDL2pp::Rect rect;
  Uint32 color;
  void draw();
  bool checkClick(const Point<int> &mousePosition);
};

#endif
