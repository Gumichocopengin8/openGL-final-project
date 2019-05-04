//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_CHUNK_H
#define PROJECT_CHUNK_H

#include "../block/Block.h"
#include "../block/types_of_block.h"
#include "../biome/BiomeType.h"

#define CHUNK_SIZE 16
#define CHUNK_HEIGHT 128

class Chunk {
    int x;
    int z;
    BiomeType* biome;

public:
    int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];
    int heights[CHUNK_SIZE][CHUNK_SIZE];
    //BiomeType biome;

    Chunk(int chunk_x, int chunk_z, BiomeType* biome);
    void render();
    int random(int max);
    int getBlock(int x, int y, int z);
    int getHeight(int x, int z);
    void generateStructures();
    void removeHiddenBlocks();
};


#endif //PROJECT_CHUNK_H
