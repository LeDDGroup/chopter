#pragma once

struct Point {
  int x, y;
  Point(int x = 0, int y = 0);
  Point operator + (const Point &b) const;
};

struct Rect {
  Point position, size;
};

bool collission(const Rect &a, const Rect &b);

bool collission(const int x1, const int x2, const int y1, const int y2);
