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
    else {
        texture.ground();
        cerr << "Unknown type " << this->type << endl;
    }

    GLUquadricObj *sphere;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluSphere(sphere, 1.0, 4.0, 4.0);

    glPopMatrix();
}
