//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_BLOCK_H
#define PROJECT_BLOCK_H

#include "types_of_block.h"


class Block {

private:
    int type;
    int x;
    int y;
    int z;

public:
  explicit Block(int type, int x, int y, int z);

    void render();
};


#endif //PROJECT_BLOCK_H
