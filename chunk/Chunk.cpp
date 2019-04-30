//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>

#include "Chunk.h"
#include "PerlinNoise.hpp"

Chunk::Chunk(int chunk_x, int chunk_z) {
    this->x = chunk_x;
    this->z = chunk_z;

    double frequency = 1;
    int octaves = 60;

    std::uint32_t seed = 1;


    const siv::PerlinNoise perlin(seed);
    const double fx = 16 / frequency;
    const double fy = 16 / frequency;

//    for (int y = 0; y < 16; ++y)
//    {
//        for (int x = 0; x < 16; ++x)
//        {
//            std::cout << perlin.octaveNoise0_1(x / fx, y / fy, octaves) << " ";
//        }
//
//        std::cout << "" << std::endl;
//    }

    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            for (int k = 0; k < CHUNK_SIZE; ++k) {

                if(j == round(perlin.octaveNoise0_1(i / fx, k / fy, octaves) * 3)) {
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
