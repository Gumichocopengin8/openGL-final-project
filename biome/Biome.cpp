//
// Created by Fabien Delattre on 2019-05-04.
//

#include <cmath>

#include "Biome.h"

Biome::Biome(int x, int z, BiomeType *type) {
    this->x = x;
    this->z = z;
    this->type = type;
}

float Biome::distance_to(float x, float z) {
    return pow(x - this->x, 2) + pow(z - this->z, 2);
}
