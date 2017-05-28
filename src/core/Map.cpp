#include <cstdlib>
#include "Map.hpp"

Map::Map(int height, int length, int updateDistance) {
  this->height = height;
  this->updateDistance = updateDistance;
  this->length = length;
  this->minSize = 4;
  this->maxSize = height - 2;
  generateMap();
  prev = 0;
}

void Map::generateMap() {
  const int startValue = length + updateDistance - 1;
  field[startValue].size = maxSize;
  field[startValue].height = height / 3;
  prev = startValue;
  for(int i = 0; i < length; i++) {
    updateBlocks(i);
  }
}

int Map::normalizeValue (int value, int minValue, int maxValue) {
  if(value > maxValue) {
    value = maxValue;
  }
  if(value < minValue) {
    value = minValue;
  }
  return value;
}

int Map::randomValue(int value) {
  int r = (random() % 3) - 1;
  return value + r;
}

void Map::updateBlocks(int position) {
  if (position != prev) {
    int updatePosition = (position + updateDistance + length) % length;
    int previousToUpdate = (updatePosition - 1 + length) % length;
    field[updatePosition].size = normalizeValue(randomValue(field[previousToUpdate].size), minSize, maxSize);
    field[updatePosition].height = normalizeValue(randomValue(field[previousToUpdate].height), 0, height - field[updatePosition].size - 2);
    prev = position;
  }
}

int Map::pxToBlock(int x, int blockWidth) {
  return x / blockWidth;
}

void Map::onStep(int position) {
  updateBlocks(position);
};
