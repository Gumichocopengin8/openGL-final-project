//
// Created by Fabien Delattre on 2019-05-04.
//

#include <cmath>
#include <utility>
#include "Biome.h"

float Biome::distance_to(float x, float z) const {
  return pow(x - this->x, 2) + pow(z - this->z, 2);
}
