#include "utils.hpp"

bool collision(const Rect &a, const Rect &b) {
  const Point &a1 = a.position;
  const Point &a2 = a.position + a.size;
  const Point &b1 = b.position;
  const Point &b2 = b.position + b.size;
  return collision(a1.x, a2.x, b1.x, b2.x) && collision(a1.y, a2.y, b1.y, b2.y);
}

bool collision(const int x1, const int x2, const int x3, const int x4) {
  if (x1 <= x4 && x2 >= x3) {
    return true;
  }
  return false;
}

Point Point::operator + (const Point &b) const {
  return Point(x + b.x, y + b.y);
}

Point::Point(int x, int y) : x(x), y(y) {
}
