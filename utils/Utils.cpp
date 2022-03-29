//
// Created by Keita Nonaka on 3/28/22.
//

#include <random>
#include "Utils.h"

int utils::random(int max) {
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen()); // 64-bit Mersenne Twister by Matsumoto and Nishimura, 2000
  std::uniform_int_distribution<> dist(0, max);
  return dist(engine);
}
