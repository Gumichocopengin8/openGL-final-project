//
// Created by Fabien Delattre on 2019-05-04.
//

#ifndef PROJECT_BIOMETYPE_H
#define PROJECT_BIOMETYPE_H


#include <iostream>
#include <string>

#include "../block/types_of_block.h"

struct BiomeType {
  BiomeType() {
    this->id = "";
    this->ground = GRASS;
  }

  explicit BiomeType(const BiomeType *pType) {
    this->id = pType->id;
    this->ground = pType->ground;
  }

  std::string id;
  int ground = GRASS;
  float tree_frequency = 0;
  float cactus_frequency = 0;
  float rock_frequency = 0;
};


#endif //PROJECT_BIOMETYPE_H
