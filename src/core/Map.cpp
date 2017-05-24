#include "Map.hpp"

Map::Map(int height, int length, int updateDistance, int minDistance) {
  this->updateDistance = updateDistance;
  this->length = length;
  this->minDistance = minDistance;
  generateMap();
}

void Map::generateMap() {
  topHeight[0] = height;
  bottomHeight[0] = 0;
  for(int i = 1; i < length; i++) {
    topHeight[i] = randomHeight(topHeight[i-1]);
    bottomHeight[i] = randomHeight(bottomHeight[i-1]);
  }
}

int randomHeight(int height) {
  return height;
}

void Map::updateBlocks(int position) {
  int updatePosition = (position + updateDistance) % length;
  int previousToUpdate = (position + updateDistance - 1) % length;
  topHeight[updatePosition] = randomHeight(topHeight[previousToUpdate]);
  bottomHeight[updatePosition] = randomHeight(bottomHeight[previousToUpdate]);
}

int Map::pxToBlock(int x, int blockWidth) {
  return x / blockWidth;
}

void Map::onStep(int position) {
  updateBlocks(position);
};
