#ifndef POINT_HPP
#define POINT_HPP

template<typename type>
class Point {
public:
  type x, y;
  Point(type x = 0, type y = 0);
  Point<type> operator + (const Point<type> &b) const;
};

template<typename type>
Point<type> Point<type>::operator + (const Point<type> &b) const {
  return Point(x + b.x, y + b.y);
}

template<typename type>
Point<type>::Point(type x, type y) : x(x), y(y) {
}

#endif
