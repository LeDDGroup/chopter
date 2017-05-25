#ifndef UTILS_HPP
#define UTILS_HPP

template<typename type>
class Point {
public:
  type x, y;
  Point(type x = 0, type y = 0);
  Point<type> operator + (const Point<type> &b) const;
};

struct Rect {
  Point<int> position, size;
};

bool collision(const Rect &a, const Rect &b);

bool collision(const int x1, const int x2, const int y1, const int y2);

#endif
