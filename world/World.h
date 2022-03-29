//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

#include <map>
#include <string>
#include <vector>

#include "../chunk/Chunk.h"
#include "../biome/BiomeType.h"
#include "../biome/Biome.h"

class World {

public:

  std::map<std::string, std::shared_ptr<Chunk>> chunks;
  std::vector<Biome> biomes;

  std::map<std::string, std::shared_ptr<BiomeType>> biome_types;


  World();

  void update(double x, double y);

  void loadChunk(int chunk_x, int chunk_y);

  std::unique_ptr<Chunk> generateChunk(int chunk_x, int chunk_y);

  std::shared_ptr<BiomeType> chooseChunkBiome(int chunk_x, int chunk_y);

  int getBlock(int x, int y, int z);

  int getTerrainHeight(int x, int z);

  std::vector<std::shared_ptr<Chunk>> getNeighborsChunks(int x, int z);


  void initializeBiomes();
};


#endif //PROJECT_WORLD_H
