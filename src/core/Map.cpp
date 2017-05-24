#include "Map.hpp"

Map::Map(int updateDistance, int length, int minDistance) {
  this->updateDistance = updateDistance;
  this->length = length;
  this->minDistance = minDistance;
  generateMap();
}

void Map::generateMap() {
}

void Map::updateBlocks(int position) {
}

int Map::pxToBlock(int x, int blockWidth) {
  return x / blockWidth;
}

void Map::onStep(int position) {
  updateBlocks(position);
};
