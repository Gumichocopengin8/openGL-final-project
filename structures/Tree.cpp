//
// Created by Fabien Delattre on 2019-05-01.
//

#include "Tree.h"
#include <random>
#include <cmath>

#define MIN_HEIGHT_TREE 8
#define MAX_HEIGHT_TREE 12

#define MIN_RADIUS_TREE 3
#define MAX_RADIUS_TREE 6


Tree::Tree(int x, int y, int z, Chunk *chunk) {

    int height_tree = MIN_HEIGHT_TREE + rand() % (MAX_HEIGHT_TREE - MIN_HEIGHT_TREE);

    for (int i = 0; i < height_tree; ++i) {
        if (chunk->blocks[x][y + i][z] == AIR) {
            chunk->blocks[x][y + i][z] = TREETRUNK;
        }
    }


    int radius_tree = MIN_RADIUS_TREE + rand() % (MAX_RADIUS_TREE - MIN_RADIUS_TREE);
    int texture = this->chooseTexture();

    for (int i = -radius_tree + 1; i <= radius_tree - 1; i++) {
        for (int j = -radius_tree + 1; j <= radius_tree - 1; j++) {
            for (int k = y + height_tree - radius_tree + 1; k < y + height_tree - radius_tree + 2; ++k) {
                if (z + j < 16 && x + i < 16 && x + i > -1 && z + j > -1) {
                    if (chunk->blocks[x + i][k][z + j] == AIR) {
                        chunk->blocks[x + i][k][z + j] = texture;
                    }
                }
            }
        }
    }


    for (int i = -radius_tree; i <= radius_tree; i++) {
        for (int j = -radius_tree; j <= radius_tree; j++) {
            for (int k = y + height_tree - radius_tree + 2; k < y + height_tree + radius_tree - 1; ++k) {
                if (z + j < 16 && x + i < 16 && x + i > -1 && z + j > -1) {
                    if (chunk->blocks[x + i][k][z + j] == AIR) {
                        chunk->blocks[x + i][k][z + j] = texture;
                    }
                }
            }
        }
    }


    for (int i = -radius_tree + 1; i <= radius_tree - 1; i++) {
        for (int j = -radius_tree + 1; j <= radius_tree - 1; j++) {
            for (int k = y + height_tree + radius_tree - 1; k < y + height_tree + radius_tree; ++k) {
                if (z + j < 16 && x + i < 16 && x + i > -1 && z + j > -1) {
                    if (chunk->blocks[x + i][k][z + j] == AIR) {
                        chunk->blocks[x + i][k][z + j] = texture;
                    }
                }
            }
        }
    }
}

int Tree::chooseTexture() {
    int num = rand() % 100;
    int texture = 0;
    if (0 <= num && num < 33) {
        texture = TREELEAVES;
    } else if (33 <= num && num < 66) {
        texture = ORANGE;
    } else {
        texture = LAWNGREEN;
    }
    return texture;
}
