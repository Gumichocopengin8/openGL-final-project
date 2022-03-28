//
// Created by Keita Nonaka on 2019-05-04.
//

#ifndef PROJECT_SNOWFLAKE_H
#define PROJECT_SNOWFLAKE_H

#include "../chunk/Chunk.h"

class SnowFlake {
private:
  int fall_speed;
public:
  explicit SnowFlake() : fall_speed{0} {};

  void snowGenerate(int x, int y, int z, Chunk *chunk);

  void snowFall();
};


#endif //PROJECT_SNOWFLAKE_H
