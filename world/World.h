//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

#include <map>
#include <string>

#include "../chunk/Chunk.h"

class World {
    //std::map<char[], Chunk> chunks;
public:
    World();
    void update(double x, double y);
    void loadChunk(int chunk_x, int chunk_y);
    void generateChunk(int chunk_x, int chunk_y);
};


#endif //PROJECT_WORLD_H
