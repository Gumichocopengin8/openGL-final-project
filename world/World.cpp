//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <string>
#include <cmath>
#include "World.h"


World::World() {
    this->chunks = std::map<std::string, Chunk *>();
}

void World::update(double x, double y) {


    int chunk_x = floor(x / CHUNK_SIZE);
    int chunk_y = floor(y / CHUNK_SIZE);


    for (int i = chunk_x - 3; i <= chunk_x + 3; i++) {
        for (int j = chunk_y - 3; j <= chunk_y + 3; j++) {
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
    std::string key = std::to_string(chunk_x) + "_" + std::to_string(chunk_y);


    int biome = this->chooseChunkBiome(chunk_x, chunk_y);

    Chunk *chunk = NULL;
    chunk = new Chunk(chunk_x, chunk_y, 0);

    return chunk;
}

int World::getBlock(int x, int y, int z) {

    //std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

    std::string key = std::to_string(floor(x / 16.0)) + "_" + std::to_string(floor(z / 16.0));

    Chunk *chunk = NULL;

    if (this->chunks.count(key) > 0) {
        chunk = this->chunks[key];
    } else {
        //std::cerr << "The requested block belongs to a not loaded chunk." << std::endl;
        return 10;

    }

    x = x % 16;
    if (x < 0) {
        x += 16;
    }

    z = z % 16;
    if (z < 0) {
        z += 16;
    }

    return chunk->getBlock(x, y, z);

}

int World::getTerrainHeight(int x, int z) {
    std::string key = std::to_string(int(floor(x / 16.0))) + "_" + std::to_string(int(floor(z / 16.0)));
    Chunk *chunk = nullptr;
    if (this->chunks.count(key) > 0) {
        chunk = this->chunks[key];
    } else {
        return -1;
    }

    x = x % 16;
    if (x < 0) {
        x += 16;
    }

    z = z % 16;
    if (z < 0) {
        z += 16;
    }

    return chunk->getHeight(x, z);

}

int World::chooseChunkBiome(int chunk_x, int chunk_y) {

    return 0;
}
