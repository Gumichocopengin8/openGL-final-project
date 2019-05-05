//
// Created by Fabien Delattre on 2019-04-19.
//

#include "Block.h"
#include "../texture/Texture.h"
#include <iostream>
#include <cstdlib>
#import <GLUT/glut.h>

#include "../main.h"

using namespace std;

Block::Block(int type, int x, int y, int z) {
    this->type = type;
    this->x = x;
    this->y = y;
    this->z = z;
}

void Block::render() {

    // Transforms
    glPushMatrix();
    glTranslated(x, y, z);

    // Texture
    Texture texture;

    if (this->type == GROUND) { texture.ground(); }
    else if (this->type == GRASS) { texture.grass(); }
    else if (this->type == TREETRUNK) { texture.treeTrunk(); }
    else if (this->type == TREELEAVES) { texture.treeLeaves(); }
    else if (this->type == SNOW) { texture.snow(); }
    else if (this->type == WATER) { texture.water(); }
    else if (this->type == CLOUD ) { texture.cloud(); }
    else if (this->type == ORANGE ) { texture.orange(); }
    else if (this->type == LAWNGREEN ) { texture.lawngreen(); }
    else if (this->type == SAND ) { texture.sand(); }
    else if (this->type == ROCK ) { texture.rock(); }
    else { texture.ground(); }

    glutSolidCube(1);
    glPopMatrix();
}