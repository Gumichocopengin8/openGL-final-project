//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <string>

#include "Chunk.h"
#include "PerlinNoise.hpp"

#include "../structures/Tree.h"

#include "../main.h"

using namespace std;

Chunk::Chunk(int chunk_x, int chunk_z, int biome) {
    this->x = chunk_x;
    this->z = chunk_z;
    this->biome = biome;


    // PerlinNoise Setup
    uint32_t seed = rand();
    double frequency = 0.1;
    int octaves = 4;
    const siv::PerlinNoise perlin(seed);
    const double fx = 16 / frequency;
    const double fy = 16 / frequency;


    for (int i = 0; i < CHUNK_SIZE; i++) {
        float new_percent_i = i;
        if (CHUNK_SIZE - 1 - i < new_percent_i) {
            new_percent_i = CHUNK_SIZE - 1 - i;
        }
        new_percent_i++;
        new_percent_i *= 0.2;
        if (new_percent_i > 1) {
            new_percent_i = 1;
        }
        for (int j = 0; j < CHUNK_SIZE; j++) {


            float new_percent_j = j;
            if (CHUNK_SIZE - 1 - j < new_percent_j) {
                new_percent_j = CHUNK_SIZE - 1 - j;
            }
            new_percent_j++;
            new_percent_j *= 0.2;
            if (new_percent_j > 1) {
                new_percent_j = 1;
            }

            int height = round(perlin.octaveNoise0_1(i / fx, j / fy, octaves) * 20);

            int old_height_i = -1;
            int old_height_j = -1;



            // Get adjacent i height

            if (i < 5) {
                int temp_old_height = worldPtr->getTerrainHeight(this->x * 16 - 1, this->z * 16 + j);

                if (temp_old_height != -1) {
                    old_height_i = temp_old_height;
                }
            }

            if (i > 10) {
                int temp_old_height = worldPtr->getTerrainHeight((1 + this->x) * 16, this->z * 16 + j);
                if (temp_old_height != -1) {
                    old_height_i = temp_old_height;
                }
            }


            // Get adjacent j height


            if (j < 5) {
                int temp_old_height = worldPtr->getTerrainHeight(this->x * 16 + i, this->z * 16 - 1);


                if (temp_old_height != -1) {
                    old_height_j = temp_old_height;
                }
            }

            if (j > 10) {
                int temp_old_height = worldPtr->getTerrainHeight(this->x * 16 + i, (1 + this->z) * 16);


                if (temp_old_height != -1) {
                    old_height_j = temp_old_height;
                }
            }


            // Compute smooth height

            if (old_height_i != -1 && old_height_j == -1) {
                height = new_percent_i * height + (1 - new_percent_i) * old_height_i;
            }
            if (old_height_i == -1 && old_height_j != -1) {
                height = new_percent_j * height + (1 - new_percent_j) * old_height_j;
            }

            if (old_height_i != -1 && old_height_j != -1) {
                float new_percent =
                        1 / ((1 - new_percent_i) / new_percent_i + (1 - new_percent_j) / new_percent_j + 1);
                height = new_percent * height +
                         (new_percent * (1 - new_percent_i) / new_percent_i) * old_height_i +
                         (new_percent * (1 - new_percent_j) / new_percent_j) * old_height_j;
            }


            this->heights[i][j] = height;
            for (int k = 0; k < CHUNK_HEIGHT; ++k) {
                if (k <= height) {
                    if(this->biome == PLAINS) {
                        this->blocks[i][k][j] = GRASS;
                    } else {
                        this->blocks[i][k][j] = SNOW;
                    }

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

int Chunk::getHeight(int x, int z) {
    return this->heights[x][z];
}
