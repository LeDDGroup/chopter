#include "utils.hpp"

bool collission(const Rect &a, const Rect &b) {
  const Point &a1 = a.position;
  const Point &a2 = a.position + a.size;
  const Point &b1 = b.position;
  const Point &b2 = b.position + b.size;
  return collission(a1.x, a2.x, b1.x, b2.x) && collission(a1.y, a2.y, b1.y, b2.y);
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
