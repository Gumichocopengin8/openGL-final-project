//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <string>
#include <cmath>
#include "World.h"
#include "../main.h"
#include "../utils/Utils.h"

World::World() {
  this->chunks = std::map<std::string, std::shared_ptr<Chunk>>();
  this->biome_types = std::map<std::string, std::shared_ptr<BiomeType>>();
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
  std::shared_ptr<Chunk> chunk;

  if (this->chunks.count(key) > 0) {
    chunk = this->chunks[key];
  } else {
    chunk = std::move(this->generateChunk(chunk_x, chunk_y));
    this->chunks[key] = chunk;
  }
  chunk->render();
}

std::unique_ptr<Chunk> World::generateChunk(int chunk_x, int chunk_y) {
  std::string key = std::to_string(chunk_x) + "_" + std::to_string(chunk_y);
  std::shared_ptr<BiomeType> biome_type = this->chooseChunkBiome(chunk_x, chunk_y);
  std::unique_ptr<Chunk> chunk(new Chunk(chunk_x, chunk_y, biome_type.get()));
  return chunk;
}

int World::getBlock(int x, int y, int z) {
  std::string key = std::to_string(int(floor(x / 16.0))) + "_" + std::to_string(int(floor(z / 16.0)));
  std::shared_ptr<Chunk> chunk;
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
  std::shared_ptr<Chunk> chunk;
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

std::shared_ptr<BiomeType> World::chooseChunkBiome(int chunk_x, int chunk_y) {
  // For the first chunk
  if (this->biomes.empty()) {
    // Force desert because the biome is cool
    std::string key = "desert";

    Biome biome(key, chunk_x, chunk_y, this->biome_types[key]);
    this->biomes.push_back(biome);
    return this->biome_types[key];
  }

  // Get the nearest biome
  float best_distance = this->biomes[0].distance_to(chunk_x, chunk_y);
  Biome best_distance_biome = this->biomes[0];

  for (int i = 1; i < this->biomes.size(); ++i) {
    float distance = this->biomes[i].distance_to(chunk_x, chunk_y);
    if (distance < best_distance) {
      best_distance = distance;
      best_distance_biome = this->biomes[i];
    }
  }

  if (best_distance > 20) {
    std::vector<std::string> possibleBiomeTypes;

    for (auto const &biome_type: this->biome_types) {
      if (biome_type.second != best_distance_biome.type) {
        possibleBiomeTypes.push_back(biome_type.first);
      }
    }

    auto it = possibleBiomeTypes.begin();
    advance(it, utils::random(RAND_MAX) % possibleBiomeTypes.size());
    Biome biome(*it, chunk_x, chunk_y, this->biome_types[*it]);
    this->biomes.push_back(biome);
    return this->biome_types[*it];
  }

  return best_distance_biome.type;
}

std::vector<std::shared_ptr<Chunk>> World::getNeighborsChunks(int x, int z) {
  std::vector<std::shared_ptr<Chunk>> neighbors;

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
  return neighbors;
}

void World::initializeBiomes() {
  this->biome_types["prairie"] = std::make_unique<BiomeType>(new BiomeType());
  this->biome_types["prairie"]->id = "prairie";
  this->biome_types["prairie"]->ground = GRASS;
  this->biome_types["prairie"]->tree_frequency = 0.02;

  this->biome_types["desert"] = std::make_unique<BiomeType>(new BiomeType());
  this->biome_types["desert"]->id = "desert";
  this->biome_types["desert"]->ground = SAND;
  this->biome_types["desert"]->cactus_frequency = 0.02;

  this->biome_types["mountain"] = std::make_unique<BiomeType>(new BiomeType());
  this->biome_types["mountain"]->id = "mountain";
  this->biome_types["mountain"]->ground = GRASS;
  this->biome_types["mountain"]->rock_frequency = 0.05;
}
