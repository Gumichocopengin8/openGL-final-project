//
// Created by Fabien Delattre on 2019-04-19.
//

#include "Block.h"
#include "../texture/Texture.h"
#import <GLUT/glut.h>

#include "../main.h"

void Block::render() const {
  // Transforms
  glPushMatrix();
  glTranslated(x, y, z);

  // Texture
  Texture texture;

  switch (this->type) {
    case GROUND:
      texture.ground();
      break;
    case GRASS:
      texture.grass();
      break;
    case TREETRUNK:
      texture.treeTrunk();
      break;
    case TREELEAVES:
      texture.treeLeaves();
      break;
    case SNOW:
      texture.snow();
      break;
    case WATER:
      texture.water();
      break;
    case CLOUD:
      texture.cloud();
      break;
    case ORANGE:
      texture.orange();
      break;
    case LAWNGREEN:
      texture.lawngreen();
      break;
    case SAND:
      texture.sand();
      break;
    case ROCK:
      texture.rock();
      break;
    default:
      texture.ground();
  }

  glutSolidCube(1);
  glPopMatrix();
}
