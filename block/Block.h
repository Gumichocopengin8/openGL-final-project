//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_BLOCK_H
#define PROJECT_BLOCK_H


class Block {

private:
    int x;
    int y;
    int z;
public:
    Block(int x, int y, int z);
    void draw();
};


#endif //PROJECT_BLOCK_H
