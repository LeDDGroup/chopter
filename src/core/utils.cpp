#include "utils.hpp"

bool collision(const Rect &a, const Rect &b) {
  const Point<int> &a1 = a.position;
  const Point<int> &a2 = a.position + a.size;
  const Point<int> &b1 = b.position;
  const Point<int> &b2 = b.position + b.size;
  return collision(a1.x, a2.x, b1.x, b2.x) && collision(a1.y, a2.y, b1.y, b2.y);
}

bool collision(const int x1, const int x2, const int x3, const int x4) {
  if (x1 <= x4 && x2 >= x3) {
    return true;
  }
  return false;
}
