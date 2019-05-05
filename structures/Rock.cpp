//
// Created by Fabien Delattre on 2019-05-04.
//

#include "Rock.h"


#include <random>

Rock::Rock(int x, int y, int z, Chunk *chunk) {

    int proba = 10;
    int proba_mount = 30;

    for (int i = -2; i < 2; ++i) {
        for (int j = -2; j < 2; ++j) {

            int random_number = rand() % 100;
            if (random_number < proba) {
                chunk->blocks[x + i][chunk->heights[x + i][z + j] + 1][z + j] = ROCK;
                int random_number = rand() % 100;
                if (random_number < proba_mount) {
                    chunk->blocks[x + i][chunk->heights[x + i][z + j] + 2][z + j] = ROCK;
                }
            }
        }
    }
}
