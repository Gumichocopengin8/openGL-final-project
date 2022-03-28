//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_CHUNK_H
#define PROJECT_CHUNK_H

#include "../block/Block.h"
#include "../block/types_of_block.h"
#include "../biome/BiomeType.h"

namespace {
  constexpr int CHUNK_SIZE = 16;
  constexpr int CHUNK_HEIGHT = 128;
}

class Chunk {
public:

  int x;
  int z;
  BiomeType *biome; // TODO

  int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE]{};
  int heights[CHUNK_SIZE][CHUNK_SIZE]{};

  explicit Chunk(int chunk_x, int chunk_z, BiomeType *biome);

  void render();

  int random(int max);

  int getBlock(int x, int y, int z);

  int getHeight(int x, int z);

  void generateStructures();

  void removeHiddenBlocks();
};


#endif //PROJECT_CHUNK_H
