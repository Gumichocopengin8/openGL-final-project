//
// Created by Fabien Delattre on 2019-05-03.
//

#include "Cactus.h"

#include <random>

Cactus::Cactus(int x, int y, int z, Chunk *chunk) {

  int x_min = 0;
  int x_max = CHUNK_SIZE - 1;
  int z_max = CHUNK_SIZE - 1;


  if (x - 4 > x_min)x_min = x - 4;
  if (x + 4 < x_max)x_max = x + 4;
  if (z + 4 < z_max)z_max = z + 4;
  if (z + 4 < z_max)z_max = z + 4;


  if (x > 2 && x < 14 && z > 2 && z < 14) {
    chunk->blocks[x][y][z] = TREELEAVES;
    chunk->blocks[x][y + 1][z] = TREELEAVES;
    chunk->blocks[x][y + 2][z] = TREELEAVES;
    chunk->blocks[x][y + 3][z] = TREELEAVES;
  }
}
