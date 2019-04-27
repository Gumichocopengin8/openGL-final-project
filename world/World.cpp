//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <cmath>
#include "World.h"


World::World() {
    this->chunks = std::map<std::string, Chunk*>();
}

void World::update(double x, double y) {


    int chunk_x = round(x / CHUNK_SIZE);
    int chunk_y = round(y / CHUNK_SIZE);


    for (int i = chunk_x - 1; i <= chunk_x + 1; i++) {
        for (int j = chunk_y - 1; j <= chunk_y + 1; j++) {
            this->loadChunk(i, j);
        }
    }

}


void World::loadChunk(int chunk_x, int chunk_y) {

    std::string key = std::to_string(chunk_x) + "_" + std::to_string(chunk_y);


    Chunk *chunk = NULL;

    if (this->chunks.count(key) > 0) {
        chunk = this->chunks[key];
    } else {
        chunk = this->generateChunk(chunk_x, chunk_y);
        this->chunks[key] = chunk;
    }

    chunk->render();
}

Chunk *World::generateChunk(int chunk_x, int chunk_y) {
    std::cout << "NEW CHUNK " << chunk_x << " " << chunk_y << std::endl;
    std::string key = std::to_string(chunk_x) + "_" + std::to_string(chunk_y);

    Chunk *chunk = NULL;
    chunk = new Chunk(chunk_x, chunk_y);

    return chunk;
}
