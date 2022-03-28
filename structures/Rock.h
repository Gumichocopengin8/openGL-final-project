//
// Created by Fabien Delattre on 2019-05-04.
//

#ifndef PROJECT_ROCK_H
#define PROJECT_ROCK_H


#include "../chunk/Chunk.h"


class Rock {
public:
    explicit Rock(int x, int y, int z, Chunk *chunk);
};


#endif //PROJECT_ROCK_H
