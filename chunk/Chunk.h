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
public:

    int x;
    int z;
    BiomeType* biome;

    int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];
    int heights[CHUNK_SIZE][CHUNK_SIZE];
    //BiomeType biome;

    Chunk(int chunk_x, int chunk_z, BiomeType* biome);
    void render();
    int random(int max);
    int getBlock(int x, int y, int z);
    int getHeight(int x, int z);
    float distance_to(Chunk* other);
    float distance_to(float x, float z);
    void generateStructures();
    void removeHiddenBlocks();
};


#endif //PROJECT_CHUNK_H
