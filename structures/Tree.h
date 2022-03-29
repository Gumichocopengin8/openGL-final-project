//
// Created by Fabien Delattre on 2019-05-01.
//

#ifndef PROJECT_TREE_H
#define PROJECT_TREE_H


#include "../chunk/Chunk.h"

class Tree {
public:
  explicit Tree(int x, int y, int z, Chunk *chunk);

  static int chooseTexture();
};


#endif //PROJECT_TREE_H
