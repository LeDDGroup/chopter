#include "Map.hpp"

Map::Map(int height, int length, int updateDistance) {
  this->updateDistance = updateDistance;
  this->length = length;
  generateMap();
}

void Map::generateMap() {
  field[0].size = 6;
  field[0].height = height/2;
  for(int i = 1; i < length; i++) {
    field[i].size = randomValue(field[i-1].size);
    field[i].height = randomValue(field[i-1].height);
  }
}

int Map::randomValue(int value) {
  return value;
}

void Map::updateBlocks(int position) {
  int updatePosition = (position + updateDistance) % length;
  int previousToUpdate = (position + updateDistance - 1) % length;
  field[updatePosition].size = randomValue(field[previousToUpdate].size);
  field[updatePosition].height = randomValue(field[previousToUpdate].height);
}

int Map::pxToBlock(int x, int blockWidth) {
  return x / blockWidth;
}

void Map::onStep(int position) {
  updateBlocks(position);
};
