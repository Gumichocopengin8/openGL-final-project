//
// Created by Fabien Delattre on 2019-05-03.
//

#ifndef PROJECT_BIOME_H
#define PROJECT_BIOME_H

#include "../block/types_of_block.h"

struct Biome {
    int ground;
    float treesFrequency;
    float cactusFrequency;

    Biome(
            int ground = GRASS,
            float treesFrequency = 0
            float cactusFrequency = 0) :

            ground(ground),
            treesFequency(treesFrequency),
            cactusFequency(cactusFrequency)

            {};
};


Biome prarie(ground=GRASS, treesFequency=0.1);
Biome forest(ground=GRASS, treesFequency=0.8);
Biome desert(cactusFrequency=0.1);



#endif //PROJECT_BIOME_H
