#include <cstdlib>
#include "Map.hpp"

Map::Map(int height, int length, int updateDistance) {
  this->height = height;
  this->updateDistance = updateDistance;
  this->length = length;
  generateMap();
  prev = 0;
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
  int r = (random() % 3) - 1;
  return value + r;
}

void Map::updateBlocks(int position) {
  if (position != prev) {
    int updatePosition = (position + updateDistance + length) % length;
    int previousToUpdate = (updatePosition - 1 + length) % length;
    field[updatePosition].size = randomValue(field[previousToUpdate].size);
    field[updatePosition].height = randomValue(field[previousToUpdate].height);
    prev = position;
  }
}

int Map::pxToBlock(int x, int blockWidth) {
  return x / blockWidth;
}

void Map::onStep(int position) {
  updateBlocks(position);
};
