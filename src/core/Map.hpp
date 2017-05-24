#pragma once

#define maxWidth 10000

struct Hole {
  int height;
  int size;
};

class Map {
  int updateDistance;
  int length;
  int height;
  Hole field[maxWidth];
  int randomValue(int value);
  void generateMap();
  void updateBlocks(int x);
public:
  Map(int height = 15, int length = 40, int updateDistance = 22);
  void onStep(int position);
  int pxToBlock(int x, int blockWidth);
  int getLength() const { return this->length; }
  const Hole * getField() const { return this->field; }
};
