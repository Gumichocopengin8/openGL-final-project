//
// Created by Fabien Delattre on 2019-05-04.
//

#include <cmath>
#include <utility>
#include "Biome.h"

Biome::Biome(std::string id, int x, int z, BiomeType *type) {
  this->id = std::move(id);
  this->x = x;
  this->z = z;
  this->type = type;
}

float Biome::distance_to(float x, float z) const {
  return pow(x - this->x, 2) + pow(z - this->z, 2);
}
