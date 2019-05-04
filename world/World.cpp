//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <string>
#include <cmath>
#include "World.h"

World::World() {
    this->chunks = std::map<std::string, Chunk *>();
    this->biome_types = std::map<std::string, BiomeType *>();

    this->initializeBiomes();
}

void World::update(double x, double y) {


    int chunk_x = floor(x / CHUNK_SIZE);
    int chunk_y = floor(y / CHUNK_SIZE);


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
        this->chunks[key] = chunk;
    }

    chunk->render();
}

Chunk *World::generateChunk(int chunk_x, int chunk_y) {
    std::string key = std::to_string(chunk_x) + "_" + std::to_string(chunk_y);


    BiomeType* biome = this->chooseChunkBiome(chunk_x, chunk_y);

    Chunk *chunk = NULL;
    chunk = new Chunk(chunk_x, chunk_y, biome);

    return chunk;
}

int World::getBlock(int x, int y, int z) {

    std::string key = std::to_string(int(floor(x / 16.0))) + "_" + std::to_string(int(floor(z / 16.0)));

    Chunk *chunk = NULL;
    ///Chunk
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

BiomeType* World::chooseChunkBiome(int chunk_x, int chunk_y) {


    //int biome_odd = random() % 2;

    //getNeighborsChunks(chunk_x, chunk_y);
    return this->biome_types["prairie"];
    //return biome_odd + 1;
}

std::vector<Chunk *> World::getNeighborsChunks(int x, int z) {


    std::vector<Chunk *> neighbors;

    //std::cout << "BIOMES NEIGHBORS" << std::endl;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i != 0 && j != 0) {
                std::string key = std::to_string(x + i) + "_" + std::to_string(z + j);
                if (this->chunks.count(key) > 0) {
                    neighbors.push_back(this->chunks[key]);
                }
            }
        }
    }


//    if (this->chunks.count(key) > 0) {
//        chunk = this->chunks[key];
//    } else {
//        chunk = this->generateChunk(chunk_x, chunk_y);
//        this->chunks[key] = chunk;
//    }
//
//
//    std::string key = std::to_string(chunk_x) + "_" + std::to_string(chunk_y);


    return std::vector<Chunk *>();
}

void World::initializeBiomes() {


    this->biome_types["prairie"] = new BiomeType();
    this->biome_types["prairie"]->ground = GRASS;
    this->biome_types["prairie"]->tree_frequency = 0.2;

    this->biome_types["forest"] = new BiomeType();
    this->biome_types["forest"]->ground = GRASS;
    this->biome_types["forest"]->tree_frequency = 0.8;

    this->biome_types["desert"] = new BiomeType();
    this->biome_types["desert"]->ground = SNOW;
    this->biome_types["desert"]->cactus_frequency = 0.5;


}
