//
// Created by Keita Nonaka on 2019-05-04.
//

#include "SnowFlake.h"
#include <random>

SnowFlake::SnowFlake() {
  this->fall_speed = 0;
}

void SnowFlake::snowGenerate(int x, int y, int z, Chunk *chunk) {
  if (chunk->blocks[x][y - this->fall_speed][z] == AIR) {
    chunk->blocks[x][y - this->fall_speed][z] = SNOW;
  }
}

void SnowFlake::snowFall() {
  this->fall_speed += 1;
  if (this->fall_speed > 20) {
    this->fall_speed = 0;
  }
}
