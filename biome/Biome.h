//
// Created by Fabien Delattre on 2019-05-04.
//

#ifndef PROJECT_BIOME_H
#define PROJECT_BIOME_H

#include <iostream>
#include <string>

#include "BiomeType.h"

class Biome {
public:
  std::string id;
  int x;
  int z;
  BiomeType *type;

  explicit Biome(std::string id, int x, int z, BiomeType *type);

  [[nodiscard]] float distance_to(float x, float z) const;
};


#endif //PROJECT_BIOME_H
