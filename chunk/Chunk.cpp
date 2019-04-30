//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>

#include "Chunk.h"

Chunk::Chunk(int chunk_x, int chunk_z) {
    this->x = chunk_x;
    this->z = chunk_z;

    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            for (int k = 0; k < CHUNK_SIZE; ++k) {
                if ((j == abs(this->x)) ) {
                    this->blocks[i][j][k] = 1;
                } else {
                    this->blocks[i][j][k] = 0;
                }

            }
        }
    }
}

void Chunk::render() {
    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            for (int k = 0; k < CHUNK_SIZE; ++k) {
                if (this->blocks[i][j][k] == 1) {
                    Block(this->x * 16 + i, j, this->z * 16 + k).render();
                } else {
                }
            }
        }
    }
}

int Chunk::getBlock(int x, int y, int z) {
     return this->blocks[x][y][z];
}
