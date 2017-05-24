#pragma once

struct Point {
  int x, y;
}

struct Rect {
  Point position, size;
};

bool collission(const Rect &a, const Rect &b);

bool collission(const Point &a, const Point &b);
