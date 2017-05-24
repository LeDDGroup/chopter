#pragma once

#define maxWidth 10000

class Map {
  int updateDistance;
  int minDistance;
  int length;
  int height;
  int topHeight[maxWidth];
  int bottomHeight[maxWidth];
  int randomHeight(int  height );
  void generateMap();
  void updateBlocks(int x);
public:
  Map(int height = 15, int length = 40, int updateDistance = 5, int minDistance = 5);
  void onStep(int position);
  int pxToBlock(int x, int blockWidth);
  const int * getCeil() const { return this->topHeight; }
  const int * getFloor() const { return this->bottomHeight; }
};
