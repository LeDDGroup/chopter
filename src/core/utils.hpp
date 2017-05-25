#ifndef UTILS_HPP
#define UTILS_HPP

#include "Point.hpp"

struct Rect {
  Point<int> position, size;
};

bool collision(const Rect &a, const Rect &b);

bool collision(const int x1, const int x2, const int y1, const int y2);

#endif
