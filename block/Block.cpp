//
// Created by Fabien Delattre on 2019-04-19.
//

#include "Block.h"
#include "../texture/Texture.h"
#include <cstdlib>
#import <GLUT/glut.h>


Block::Block(int x, int y, int z) {
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
    texture.grass();
    GLUquadricObj *sphere;
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluSphere(sphere, 1.0, 10.0, 10.0);

    glPopMatrix();
}

