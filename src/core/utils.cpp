#include "utils.hpp"

bool collission(const Rect &a, const Rect &b) {
  // TODO implement
  return false;
}

bool collission(const int x1, const int x2, const int y1, const int y2) {
  // TODO implement
  return false;
}

Point Point::operator + (const Point &b) const {
  return Point(x + b.x, y + b.y);
}

Point::Point(int x, int y) : x(x), y(y) {
}
