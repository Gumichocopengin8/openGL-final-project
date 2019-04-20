//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <cmath>
#include "World.h"


World::World() {

}

void World::update(double x, double y) {


    int chunk_x = round(x / CHUNK_SIZE);
    int chunk_y = round(y / CHUNK_SIZE);


    for (int i = chunk_x-1; i <= chunk_x+1; i++) {
        for (int j = chunk_y-1; j <= chunk_y+1; j++) {
            this->loadChunk(i, j);
        }
    }

    std::cout << chunk_x << " " << chunk_y << std::endl;
}


void World::loadChunk(int chunk_x, int chunk_y) {
    Chunk chunk(chunk_x, chunk_y);
    chunk.render();
}

void World::generateChunk(int chunk_x, int chunk_y) {

}
