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


    int chunk_x = round(x / CHUNK_SIZE);
    int chunk_y = round(y / CHUNK_SIZE);


    for (int i = chunk_x - 2; i <= chunk_x + 2; i++) {
        for (int j = chunk_y - 2; j <= chunk_y + 2; j++) {
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
        std::cout << "key: " << key << std::endl;
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

int World::getBlock(int x, int y, int z) {

    //std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;

    std::string key = std::to_string((int) x / 16) + "_" + std::to_string(int(z / 16));

    Chunk *chunk = NULL;

    if (this->chunks.count(key) > 0) {
        chunk = this->chunks[key];
    } else {
        std::cerr << "The requested block belongs to a not loaded chunk." << std::endl;
        return 0;

    }

//    for (int i = 0; i < 16; ++i) {
//        for (int j = 0; j < 16; ++j) {
//            if(i == x % 16 && j== z % 16 ){
//                std::cout << 'X';
//            } else {
//                std::cout << chunk->getBlock(i % 16, 1, j % 16);
//            }
//
//        }
//
//        std::cout << "" << std::endl;
//    }

    x = x % 16;
    if (x < 0) {
        x += 16;
    }

    z = z % 16;
    if (z < 0) {
        z += 16;
    }

    std::cout << "key: " << key << std::endl;
    std::cout << "getBlock(" << x << ", " << y << ", " << z << ") = " << chunk->getBlock(x, y, z) << std::endl;

    return chunk->getBlock(x, y, z);

}
