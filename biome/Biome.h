//
// Created by Fabien Delattre on 2019-05-04.
//

#ifndef PROJECT_BIOME_H
#define PROJECT_BIOME_H

#include "BiomeType.h"

class Biome {

public:
    int x;
    int z;
    BiomeType* type;

    Biome(int x, int z, BiomeType* type);
};


#endif //PROJECT_BIOME_H
