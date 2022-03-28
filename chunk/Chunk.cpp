//
// Created by Fabien Delattre on 2019-04-20.
//

#include <iostream>
#include <random>
#include <string>

#include "Chunk.h"
#include "PerlinNoise.hpp"

#include "../structures/Tree.h"
#include "../structures/Cactus.h"
#include "../structures/Rock.h"
#include "../structures/Cloud.h"
#include "../structures/SnowFlake.h"
#include "../main.h"
#include "../utils/Utils.h"


Chunk::Chunk(int chunk_x, int chunk_z, BiomeType *biome) {
  this->x = chunk_x;
  this->z = chunk_z;
  this->biome = biome;


  // PerlinNoise Setup
  uint32_t seed = utils::random(RAND_MAX);
  double frequency = 0.1;
  int octaves = 4;
  const siv::PerlinNoise perlin(seed);
  const double fx = 16 / frequency;
  const double fy = 16 / frequency;


  for (int i = 0; i < CHUNK_SIZE; i++) {
    float new_percent_i = i;
    if (CHUNK_SIZE - 1 - i < new_percent_i)
      new_percent_i = CHUNK_SIZE - 1 - i;

    new_percent_i++;
    new_percent_i *= 0.2;
    if (new_percent_i > 1)new_percent_i = 1;

    for (int j = 0; j < CHUNK_SIZE; j++) {
      float new_percent_j = j;

      if (CHUNK_SIZE - 1 - j < new_percent_j)
        new_percent_j = CHUNK_SIZE - 1 - j;
      new_percent_j++;
      new_percent_j *= 0.2;
      if (new_percent_j > 1) new_percent_j = 1;


      float height = roundf(
        perlin.octaveNoise0_1(i / fx, j / fy, octaves) * (this->biome->id == "mountain" ? 40 : 20));

      float old_height_i = -1;
      float old_height_j = -1;


      // Get adjacent i height

      if (i < 5) {
        int temp_old_height = worldPtr->getTerrainHeight(this->x * 16 - 1, this->z * 16 + j);

        if (temp_old_height != -1)
          old_height_i = temp_old_height;
      }

      if (i > 10) {
        float temp_old_height = worldPtr->getTerrainHeight((1 + this->x) * 16, this->z * 16 + j);
        if (temp_old_height != -1)
          old_height_i = temp_old_height;
      }

      // Get adjacent j height

      if (j < 5) {
        float temp_old_height = worldPtr->getTerrainHeight(this->x * 16 + i, this->z * 16 - 1);

        if (temp_old_height != -1)
          old_height_j = temp_old_height;
      }

      if (j > 10) {
        float temp_old_height = worldPtr->getTerrainHeight(this->x * 16 + i, (1 + this->z) * 16);

        if (temp_old_height != -1)
          old_height_j = temp_old_height;
      }


      // Compute smooth height

      if (old_height_i != -1 && old_height_j == -1) {
        height = new_percent_i * height + (1 - new_percent_i) * old_height_i;
      }
      if (old_height_i == -1 && old_height_j != -1) {
        height = new_percent_j * height + (1 - new_percent_j) * old_height_j;
      }

      if (old_height_i != -1 && old_height_j != -1) {
        float new_percent =
          1 / ((1 - new_percent_i) / new_percent_i + (1 - new_percent_j) / new_percent_j + 1);
        height = round(new_percent * height +
                       (new_percent * (1 - new_percent_i) / new_percent_i) * old_height_i +
                       (new_percent * (1 - new_percent_j) / new_percent_j) * old_height_j);
      }


      this->heights[i][j] = height;

      for (int k = 0; k < CHUNK_HEIGHT; ++k) {
        if (k <= height) {
          int water_level = 7;

          if (k <= water_level) {
            this->blocks[i][water_level][j] = WATER;
          } else {
            this->blocks[i][k][j] = this->biome->ground;
            std::string key;

            key = std::to_string(this->x + 1) + "_" + std::to_string(this->z);
            if (worldPtr->chunks.count(key) > 0) {
              if (this->biome != worldPtr->chunks[key]->biome) {
                int random_number = utils::random(RAND_MAX) % 100;
                int prob_actual_next_ground = 0;

                if (i == CHUNK_SIZE - 1) prob_actual_next_ground = 80;
                if (i == CHUNK_SIZE - 2) prob_actual_next_ground = 20;
                if (random_number < prob_actual_next_ground) {
                  this->blocks[i][k][j] = worldPtr->chunks[key]->biome->ground;
                }
              }
            }


            key = std::to_string(this->x) + "_" + std::to_string(this->z + 1);
            if (worldPtr->chunks.count(key) > 0) {
              if (this->biome != worldPtr->chunks[key]->biome) {
                int random_number = utils::random(RAND_MAX) % 100;
                int prob_actual_next_ground = 0;

                if (j == CHUNK_SIZE - 1) prob_actual_next_ground = 80;
                if (j == CHUNK_SIZE - 2) prob_actual_next_ground = 20;
                if (random_number < prob_actual_next_ground) {
                  this->blocks[i][k][j] = worldPtr->chunks[key]->biome->ground;
                }
              }
            }


            key = std::to_string(this->x - 1) + "_" + std::to_string(this->z);
            if (worldPtr->chunks.count(key) > 0) {
              if (this->biome != worldPtr->chunks[key]->biome) {
                int random_number = utils::random(RAND_MAX) % 100;
                int prob_actual_next_ground = 0;

                if (i == 0) prob_actual_next_ground = 80;
                if (i == 1) prob_actual_next_ground = 20;
                if (random_number < prob_actual_next_ground) {
                  this->blocks[i][k][j] = worldPtr->chunks[key]->biome->ground;
                }
              }
            }


            key = std::to_string(this->x) + "_" + std::to_string(this->z - 1);
            if (worldPtr->chunks.count(key) > 0) {
              if (this->biome != worldPtr->chunks[key]->biome) {
                int random_number = utils::random(RAND_MAX) % 100;
                int prob_actual_next_ground = 0;

                if (j == 0) prob_actual_next_ground = 80;
                if (j == 1) prob_actual_next_ground = 20;
                if (random_number < prob_actual_next_ground) {
                  this->blocks[i][k][j] = worldPtr->chunks[key]->biome->ground;
                }
              }
            }


          }

          int snow_level_min = 23;

          if (k > snow_level_min + 3 * sin(0.1 * (i + j))) {
            this->blocks[i][k][j] = SNOW;
          }
        } else {
          if (this->blocks[i][k][j] != WATER) {
            this->blocks[i][k][j] = AIR;
          }
        }
      }
    }
  }

  this->generateStructures();
  this->removeHiddenBlocks();
}

void Chunk::render() {
  for (int i = 0; i < CHUNK_SIZE; ++i) {
    for (int j = 0; j < CHUNK_HEIGHT; ++j) {
      for (int k = 0; k < CHUNK_SIZE; ++k) {
        if (this->blocks[i][j][k] != AIR) {
          Block(this->blocks[i][j][k], this->x * 16 + i, j, this->z * 16 + k).render();
        }
      }
    }
  }
}

int Chunk::getBlock(int x, int y, int z) {
  return this->blocks[x][y][z];
}

int Chunk::getHeight(int x, int z) {
  return this->heights[x][z];
}

void Chunk::removeHiddenBlocks() {
  for (int i = 1; i < CHUNK_SIZE - 1; ++i) {
    for (int j = 1; j < CHUNK_HEIGHT - 1; ++j) {
      for (int k = 1; k < CHUNK_SIZE - 1; ++k) {
        if (
          this->blocks[i - 1][j][k] != AIR &&
          this->blocks[i + 1][j][k] != AIR &&
          this->blocks[i][j - 1][k] != AIR &&
          this->blocks[i][j + 1][k] != AIR &&
          this->blocks[i][j][k - 1] != AIR &&
          this->blocks[i][j][k + 1] != AIR) {
          this->blocks[i][j][k] = AIR;
        }
      }
    }
  }
}

void Chunk::generateStructures() {
  for (int i = 5; i < CHUNK_SIZE - 5; ++i) {
    for (int j = 5; j < CHUNK_SIZE - 5; ++j) {

      // Get surface_height
      int surface_height = this->heights[i][j];
      auto random_number = utils::random(100);

      // Trees
      if (random_number < this->biome->tree_frequency * 100) {
        Tree(i, surface_height, j, this);
        break;
      }

      // Cactus
      if (random_number < this->biome->cactus_frequency * 100) {
        Cactus(i, surface_height, j, this);
        break;
      }

      // Cactus
      if (random_number < this->biome->rock_frequency * 100) {
        Rock(i, surface_height, j, this);
        break;
      }
    }
  }

  // Cloud
  for (int i = 5; i < CHUNK_SIZE - 5; ++i) {
    for (int j = 5; j < CHUNK_SIZE - 5; ++j) {
      int prob = utils::random(1000);
      if (prob < 50) {
        int surface_height = 0;
        for (int k = 0; k < CHUNK_HEIGHT; ++k) {
          if (this->blocks[i][k][j] != AIR) surface_height = k;
        }
        Cloud(i + 10, surface_height + 20, j, this);
      }
    }
  }
}
