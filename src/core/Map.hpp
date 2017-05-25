#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"

#define maxWidth 10000

struct Hole {
  int height;
  int size;
};

class Map {
  bool status;
  int updateDistance;
  int length;
  int height;
  int prev;
  int minSize;
  int maxSize;
  int minHeight;
  int maxHeight;
  Hole field[maxWidth];
  int randomValue(int value);
  int normalizeValue(int value, int minValue, int maxValue);
  void generateMap();
  void updateBlocks(int x);
public:
  Map(int height = 15, int length = 21, int updateDistance = -3);
  void onStep(int position);
  bool checkCollision(const Rect &rect) const; // TODO implement
  int pxToBlock(int x, int blockWidth);
  int getLength() const { return this->length; }
  const Hole * getField() const { return this->field; }
};

#endif
