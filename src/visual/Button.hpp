#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2pp/Rect.hh>
#include "../core/Point.hpp"

class Button: public SDL2pp::Rect {
  bool selected;
  Uint32 color;
public:
  Button();
  void draw();
  bool checkClick(const Point<int> &mousePosition);
  Uint32 getColor() const { return color; };
  void setColor(Uint32 other) { color = other; };
  void select() { selected = true; }
  void unselect() { selected = false; }
  SDL2pp::Rect operator = (const SDL2pp::Rect & other) {
    x = other.x; y = other.y;
    w = other.w; h = other.h;
  }
};

#endif
