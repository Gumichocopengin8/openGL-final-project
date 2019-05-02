//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_CHUNK_H
#define PROJECT_CHUNK_H

#include "../block/Block.h"
#include "../block/types_of_block.h"

#define CHUNK_SIZE 16

class Chunk {
    int blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
    int x;
    int z;
public:
    Chunk(int chunk_x, int chunk_z);
    void render();
    int getBlock(int x, int y, int z);
};


#endif //PROJECT_CHUNK_H
