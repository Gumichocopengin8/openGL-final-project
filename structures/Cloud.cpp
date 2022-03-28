//
// Created by Keita Nonaka on 2019-05-03.
//

#include "Cloud.h"
#include "../utils/Utils.h"
#include <random>


namespace {
  constexpr int MIN_RADIUS_CLOUD = 8;
  constexpr int MAX_RADIUS_CLOUD = 15;
}

Cloud::Cloud(int x, int y, int z, Chunk *chunk) {
  int radius_cloud = MIN_RADIUS_CLOUD + utils::random(MAX_RADIUS_CLOUD - MIN_RADIUS_CLOUD);

  for (int i = -radius_cloud; i < radius_cloud; ++i) {
    for (int j = -radius_cloud; j < radius_cloud; ++j) {
      if (z + j < 16 && x + i < 16 && x + i > -1 && z + j > -1) {
        if (chunk->blocks[x + i][y][z + j] == AIR && z % 3 != 0)
          chunk->blocks[x + i][y][z + j] = CLOUD;
      }
    }
  }
}
