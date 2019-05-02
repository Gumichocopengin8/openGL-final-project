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

//    GLUquadricObj *sphere;
//    sphere = gluNewQuadric();
//    gluQuadricDrawStyle(sphere, GLU_FILL);
//    gluSphere(sphere, 1.0, 4.0, 4.0);


    glutSolidCube(1);


//
//    // Top face
//    if(worldPtr->getBlock(this->x, this->y+1, this->z) == AIR) {
//        glBegin(GL_POLYGON);
//        glVertex3f(1.0f, 1.0f, -1.0f);  // Top-right of top face
//        glVertex3f(-1.0f, 1.0f, -1.0f);  // Top-left of top face
//        glVertex3f(-1.0f, 1.0f, 1.0f);  // Bottom-left of top face
//        glVertex3f(1.0f, 1.0f, 1.0f);  // Bottom-right of top face
//        glEnd();
//    }
//
//
////    // Bottom face
////    if(worldPtr->getBlock(this->x, this->y-1, this->z) == AIR) {
//        glBegin(GL_POLYGON);
//        glVertex3f(1.0f, -1.0f, -1.0f); // Top-right of bottom face
//        glVertex3f(-1.0f, -1.0f, -1.0f); // Top-left of bottom face
//        glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom-left of bottom face
//        glVertex3f(1.0f, -1.0f, 1.0f); // Bottom-right of bottom face
//        glEnd();
////    }
//
//    // Front face
//    //if(worldPtr->getBlock(this->x+1, this->y, this->z) == AIR) {
//        glBegin(GL_POLYGON);
//        glVertex3f(1.0f, 1.0f, 1.0f);  // Top-Right of front face
//        glVertex3f(-1.0f, 1.0f, 1.0f);  // Top-left of front face
//        glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom-left of front face
//        glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom-right of front face
//        glEnd();
//    //}
////    // Back face
//    //if(worldPtr->getBlock(this->x-1, this->y, this->z) == AIR) {
//        glBegin(GL_POLYGON);
//        glVertex3f(1.0f, -1.0f, -1.0f); // Bottom-Left of back face
//        glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom-Right of back face
//        glVertex3f(-1.0f, 1.0f, -1.0f); // Top-Right of back face
//        glVertex3f(1.0f, 1.0f, -1.0f); // Top-Left of back face
//        glEnd();
//    //}
////
////    // Left face
//    //if(worldPtr->getBlock(this->x, this->y, this->z+1) == AIR) {
//        glBegin(GL_POLYGON);
//        glVertex3f(-1.0f, 1.0f, 1.0f);  // Top-Right of left face
//        glVertex3f(-1.0f, 1.0f, -1.0f);  // Top-Left of left face
//        glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom-Left of left face
//        glVertex3f(-1.0f, -1.0f, 1.0f);  // Bottom-Right of left face
//        glEnd();
//    //}
////
////    // Right face
//    //if(worldPtr->getBlock(this->x, this->y, this->z-1) == AIR) {
//        glBegin(GL_POLYGON);
//        glVertex3f(1.0f, -1.0f, 1.0f);  // Bottom-Right of l
//        glVertex3f(1.0f, -1.0f, -1.0f);  // Bottom-Left of left face
//        glVertex3f(1.0f, 1.0f, -1.0f);  // Top-Left of left face
//        glVertex3f(1.0f, 1.0f, 1.0f);  // Top-Right of left face
//        glEnd();
//    //}


//    glBegin(GL_POLYGON);
//    // top
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    glEnd();


    glPopMatrix();
}
