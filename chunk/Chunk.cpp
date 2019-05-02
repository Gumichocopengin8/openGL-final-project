//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>

#include "Chunk.h"
#include "PerlinNoise.hpp"
using namespace std;

Chunk::Chunk(int chunk_x, int chunk_z) {
    this->x = chunk_x;
    this->z = chunk_z;

    double frequency = 1;
    int octaves = 6;

    uint32_t seed = rand();


    const siv::PerlinNoise perlin(seed);
    const double fx = 16 / frequency;
    const double fy = 16 / frequency;

//    for (int y = 0; y < 16; ++y)
//    {
//        for (int x = 0; x < 16; ++x)
//        {
//            cout << perlin.octaveNoise0_1(x / fx, y / fy, octaves) << " ";
//        }
//
//        cout << "" << endl;
//    }

    for (int i = 0; i < CHUNK_SIZE; ++i) {
        for (int j = 0; j < CHUNK_SIZE; ++j) {
            for (int k = 0; k < CHUNK_SIZE; ++k) {

                if(j == round(perlin.octaveNoise0_1(i / fx, k / fy, octaves) * 10)) {
                //if(j == 0) {
                    if(j <= 1) {
                        this->blocks[i][j][k] = GROUND;
                    } else {
                        this->blocks[i][j][k] = GRASS;
                    }

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
