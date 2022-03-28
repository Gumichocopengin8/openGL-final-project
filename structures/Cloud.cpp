//
// Created by Keita Nonaka on 2019-05-03.
//

#include "Cloud.h"
#include <random>


namespace {
  constexpr int MIN_RADIUS_CLOUD = 8;
  constexpr int MAX_RADIUS_CLOUD = 15;
}

Cloud::Cloud(int x, int y, int z, Chunk *chunk) {
  int radius_cloud = MIN_RADIUS_CLOUD + this->random(MAX_RADIUS_CLOUD - MIN_RADIUS_CLOUD);

  for (int i = -radius_cloud; i < radius_cloud; ++i) {
    for (int j = -radius_cloud; j < radius_cloud; ++j) {
      if (z + j < 16 && x + i < 16 && x + i > -1 && z + j > -1) {
        if (chunk->blocks[x + i][y][z + j] == AIR && z % 3 != 0)
          chunk->blocks[x + i][y][z + j] = CLOUD;
      }
    }
  }
}

int Cloud::random(int max) {
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen()); // 64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
  std::uniform_int_distribution<> dist(0, max);
  return dist(engine);
}
