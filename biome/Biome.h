//
// Created by Fabien Delattre on 2019-05-04.
//

#ifndef PROJECT_BIOME_H
#define PROJECT_BIOME_H

#include <iostream>
#include <string>
#include <utility>

#include "BiomeType.h"

class Biome {
public:
  [[maybe_unused]] std::string id;
  int x;
  int z;
  std::shared_ptr<BiomeType> type;

  explicit Biome(std::string id, int x, int z, std::shared_ptr<BiomeType> type) : id{std::move(id)}, x{x}, z{z},
                                                                                  type{std::move(type)} {};

  [[nodiscard]] float distance_to(float x, float z) const;
};


#endif //PROJECT_BIOME_H
