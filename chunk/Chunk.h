//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_CHUNK_H
#define PROJECT_CHUNK_H

#include "../block/Block.h"

#define CHUNK_SIZE 16

class Chunk {
    Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
public:
    Chunk();
};


#endif //PROJECT_CHUNK_H
