//
// Created by Fabien Delattre on 2019-05-03.
//

#include "Cactus.h"

#include <random>

Cactus::Cactus(int x, int y, int z, Chunk *chunk) {


    int x_min = 0;
    int x_max = CHUNK_SIZE-1;
    int z_min = 0;
    int z_max = CHUNK_SIZE-1;


    if(x - 4 > x_min)x_min = x - 4;
    if(x + 4 < x_max)x_max = x + 4;
    if(z + 4 < z_max)z_max = z + 4;
    if(z + 4 < z_max)z_max = z + 4;


    for (int i = x_min; i <= x_max; ++i) {
        for (int j = z_min; j <= z_max; ++j) {
            int r = rand()%2;
            if(r == 0) {
                for (int k = 0; k <= CHUNK_HEIGHT; ++k) {
                    if(chunk->blocks[i][k][j] == GRASS) {
                        chunk->blocks[i][k][j] = SNOW;
                    }
                }
            }
        }
    }

    if(x > 2 && x < 14 && z > 2 && z < 14) {
        int rand_dir = rand()%2;

        int rand_dir_2 = 1 - rand_dir;

        chunk->blocks[x][y][z] = TREELEAVES;
        chunk->blocks[x][y+1][z] = TREELEAVES;
        chunk->blocks[x][y+2][z] = TREELEAVES;
        chunk->blocks[x][y+3][z] = TREELEAVES;
    }

}
