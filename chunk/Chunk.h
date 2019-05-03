//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_CHUNK_H
#define PROJECT_CHUNK_H

#include "../block/Block.h"
#include "../block/types_of_block.h"

#define CHUNK_SIZE 16
#define CHUNK_HEIGHT 128

class Chunk {
    int x;
    int z;
    int biome;
public:
    int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];
    int heights[CHUNK_SIZE][CHUNK_SIZE];

    Chunk(int chunk_x, int chunk_z, int biome);

    void render();

    int getBlock(int x, int y, int z);
    int getHeight(int x, int z);
};


#endif //PROJECT_CHUNK_H
