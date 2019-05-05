//
// Created by Fabien Delattre on 2019-05-04.
//

#ifndef PROJECT_BIOMETYPE_H
#define PROJECT_BIOMETYPE_H


#include <iostream>
#include <string>

#include "../block/types_of_block.h"

struct BiomeType {

    std::string id;
    int ground = GRASS;
    float tree_frequency = 0;
    float cactus_frequency = 0;
};


#endif //PROJECT_BIOMETYPE_H
