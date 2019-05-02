//
// Created by Fabien Delattre on 2019-05-01.
//

#include "Tree.h"
#include <random>


#define MIN_HEIGHT_TREE 10
#define MAX_HEIGHT_TREE 15

#define MIN_RADIUS_TREE 3
#define MAX_RADIUS_TREE 8


Tree::Tree(int x, int y, int z, Chunk *chunk) {

    int height_tree = MIN_HEIGHT_TREE + rand() % (MAX_HEIGHT_TREE - MIN_HEIGHT_TREE);

    for (int i = 0; i < height_tree; ++i) {
        if (chunk->blocks[x][y + i][z] == AIR) {
            chunk->blocks[x][y + i][z] = 1;
        }
    }


    int radius_tree = MIN_RADIUS_TREE + rand() % (MAX_RADIUS_TREE - MIN_RADIUS_TREE);

    for (int i = -radius_tree; i < radius_tree; ++i) {
        for (int j = -radius_tree; j < radius_tree; ++j) {
            for (int k = y + height_tree - radius_tree; k < y + height_tree + radius_tree; ++k) {

                if (z + j < 16 && x + i < 16 && x + i > -1 && z + j > -1) {
                    if (chunk->blocks[x + i][k][z + j] == AIR) {
                        chunk->blocks[x + i][k][z + j] = 2;
                    }
                }

            }
        }
    }


}