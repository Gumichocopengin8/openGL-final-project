//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

#include <map>
#include <string>
#include <vector>

#include "../chunk/Chunk.h"
#include "../chunk/types_of_biome.h"

class World {

public:

    std::map<std::string, Chunk *> chunks;

    World();

    void update(double x, double y);

    void loadChunk(int chunk_x, int chunk_y);

    Chunk *generateChunk(int chunk_x, int chunk_y);

    int chooseChunkBiome(int chunk_x, int chunk_y);

    int getBlock(int x, int y, int z);

    int getTerrainHeight(int x, int z);

    std::vector<Chunk*> getNeighborsChunks(int x, int z);

};


#endif //PROJECT_WORLD_H
