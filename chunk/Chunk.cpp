//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>

#include "Chunk.h"

Chunk::Chunk(int chunk_x, int chunk_y) {
    this->x = chunk_x;
    this->y = chunk_y;

    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            for (int k = 0; k < CHUNK_SIZE; ++k) {
                if (j == 0) {
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
                    Block(this->x * 16 + i, j, this->y * 16 + k).render();
                } else {
                }
            }
        }
    }
}
