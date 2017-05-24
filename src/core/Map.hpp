#pragma once

#define maxWidth 10000

class Map {
  int updateDistance;
  int minDistance;
  int length;
  int topHeight[maxWidth];
  int bottomHeight[maxWidth];
  void generateMap();
  void updateBlocks(int x);
public:
  Map(int updateDistance = 5, int length = 40, int minDistance = 5);
  void onStep(int position);
  int pxToBlock(int x, int blockWidth);
};
