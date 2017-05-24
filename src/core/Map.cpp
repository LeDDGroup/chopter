#include <cstdlib>
#include "Map.hpp"

Map::Map(int height, int length, int updateDistance) {
  this->height = height;
  this->updateDistance = updateDistance;
  this->length = length;
  this->minSize = 4;
  this->maxSize = 9;
  this->minHeight = 1;
  this->maxHeight = height - maxSize - 1;
  generateMap();
  prev = 0;
}

void Map::generateMap() {
  field[0].size = maxSize;
  field[0].height = height/3;
  for(int i = 1; i < length; i++) {
    field[i].size = normalizeValue(randomValue(field[i-1].size), minSize, maxSize);
    field[i].height = normalizeValue(randomValue(field[i-1].height), minHeight, maxHeight);
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
    field[updatePosition].height = normalizeValue(randomValue(field[previousToUpdate].height), minHeight, maxHeight);
    prev = position;
  }
}

int Map::pxToBlock(int x, int blockWidth) {
  return x / blockWidth;
}

void Map::onStep(int position) {
  updateBlocks(position);
};
