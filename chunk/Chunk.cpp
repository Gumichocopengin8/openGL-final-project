//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>

#include "Chunk.h"
#include "PerlinNoise.hpp"

#include "../structures/Tree.h"

using namespace std;

Chunk::Chunk(int chunk_x, int chunk_z) {
    this->x = chunk_x;
    this->z = chunk_z;

    double frequency = 0.1;
    int octaves = 4;

    uint32_t seed = rand();


    const siv::PerlinNoise perlin(seed);
    const double fx = 16 / frequency;
    const double fy = 16 / frequency;


    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            for (int k = 0; k < CHUNK_HEIGHT; ++k) {

                if (k <= round(perlin.octaveNoise0_1(i / fx, j / fy, octaves) * 20)) {
                    if (k <= 2) {
                        this->blocks[i][k][j] = GROUND;
                    } else {
                        this->blocks[i][k][j] = GRASS;
                    }

                } else {
                    this->blocks[i][k][j] = AIR;
                }
            }
        }
    }

    for (int i = 5; i < CHUNK_SIZE - 5; ++i) {
        for (int j = 5; j < CHUNK_SIZE - 5; ++j) {

            int prob_tree = rand() % 1000;
            if (prob_tree < 2) {
                int surface_height = 0;
                for (int k = 0; k < CHUNK_HEIGHT; ++k) {
                    if (this->blocks[i][k][j] != AIR) {
                        surface_height = k;
                    }
                }

                Tree(i, surface_height, j, this);
            }


        }
    }


// Remove hidden blocks
    for (int i = 1; i < CHUNK_SIZE - 1; ++i) {
        for (int j = 1; j < CHUNK_HEIGHT - 1; ++j) {
            for (int k = 1; k < CHUNK_SIZE - 1; ++k) {
                if (
                        this->blocks[i - 1][j][k] != AIR &&
                        this->blocks[i + 1][j][k] != AIR &&
                        this->blocks[i][j - 1][k] != AIR &&
                        this->blocks[i][j + 1][k] != AIR &&
                        this->blocks[i][j][k - 1] != AIR &&
                        this->blocks[i][j][k + 1] != AIR) {
                    this->blocks[i][j][k] = AIR;
                }
            }
        }
    }


}

void Chunk::render() {
    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_HEIGHT; ++j) {
            for (int k = 0; k < CHUNK_SIZE; ++k) {
                if (this->blocks[i][j][k] != 0) {
                    Block(this->blocks[i][j][k], this->x * 16 + i, j, this->z * 16 + k).render();
                }
            }
        }
    }
}

int Chunk::getBlock(int x, int y, int z) {
    return this->blocks[x][y][z];
}
