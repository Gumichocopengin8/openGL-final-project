//
// Created by Fabien Delattre on 2019-05-01.
//

#include "Tree.h"
#include "../utils/Utils.h"
#include <random>
#include <cmath>

namespace {
  constexpr int MIN_HEIGHT_TREE = 8;
  constexpr int MAX_HEIGHT_TREE = 12;

  constexpr int MIN_RADIUS_TREE = 3;
  constexpr int MAX_RADIUS_TREE = 6;
}


Tree::Tree(int x, int y, int z, Chunk *chunk) {

  int height_tree = MIN_HEIGHT_TREE + utils::random(RAND_MAX) % (MAX_HEIGHT_TREE - MIN_HEIGHT_TREE);

  for (int i = 0; i < height_tree; ++i) {
    if (chunk->blocks[x][y + i][z] == AIR) {
      chunk->blocks[x][y + i][z] = TREETRUNK;
    }
  }


  int radius_tree = MIN_RADIUS_TREE + utils::random(RAND_MAX) % (MAX_RADIUS_TREE - MIN_RADIUS_TREE);
  int texture = Tree::chooseTexture();

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
  int num = utils::random(RAND_MAX) % 100;
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
