//
// Created by Keita Nonaka on 2019-05-03.
//

#ifndef PROJECT_CLOUD_H
#define PROJECT_CLOUD_H

#include "../chunk/Chunk.h"

class Cloud {
public:
    Cloud(int x, int y, int z, Chunk *chunk);

    int random(int max);
};


#endif //PROJECT_CLOUD_H
