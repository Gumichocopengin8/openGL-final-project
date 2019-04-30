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
    texture.ground();



    glBegin(GL_POLYGON);
    // top
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);


//// Top face
//    //glColor3f(   0.0f, 1.0f,  0.0f );  // Green
//    glVertex3f(  1.0f, 1.0f, -1.0f );  // Top-right of top face
//    glVertex3f( -1.0f, 1.0f, -1.0f );  // Top-left of top face
//    glVertex3f( -1.0f, 1.0f,  1.0f );  // Bottom-left of top face
//    glVertex3f(  1.0f, 1.0f,  1.0f );  // Bottom-right of top face
//
//    // Bottom face
//    //glColor3f(   1.0f,  0.5f,  0.0f ); // Orange
//    glVertex3f(  1.0f, -1.0f, -1.0f ); // Top-right of bottom face
//    glVertex3f( -1.0f, -1.0f, -1.0f ); // Top-left of bottom face
//    glVertex3f( -1.0f, -1.0f,  1.0f ); // Bottom-left of bottom face
//    glVertex3f(  1.0f, -1.0f,  1.0f ); // Bottom-right of bottom face
//
//    // Front face
//    //glColor3f(   1.0f,  0.0f, 0.0f );  // Red
//    glVertex3f(  1.0f,  1.0f, 1.0f );  // Top-Right of front face
//    glVertex3f( -1.0f,  1.0f, 1.0f );  // Top-left of front face
//    glVertex3f( -1.0f, -1.0f, 1.0f );  // Bottom-left of front face
//    glVertex3f(  1.0f, -1.0f, 1.0f );  // Bottom-right of front face
//
//    // Back face
//    //glColor3f(   1.0f,  1.0f,  0.0f ); // Yellow
//    glVertex3f(  1.0f, -1.0f, -1.0f ); // Bottom-Left of back face
//    glVertex3f( -1.0f, -1.0f, -1.0f ); // Bottom-Right of back face
//    glVertex3f( -1.0f,  1.0f, -1.0f ); // Top-Right of back face
//    glVertex3f(  1.0f,  1.0f, -1.0f ); // Top-Left of back face
//
//    // Left face
//    //glColor3f(   0.0f,  0.0f,  1.0f);  // Blue
//    glVertex3f( -1.0f,  1.0f,  1.0f);  // Top-Right of left face
//    glVertex3f( -1.0f,  1.0f, -1.0f);  // Top-Left of left face
//    glVertex3f( -1.0f, -1.0f, -1.0f);  // Bottom-Left of left face
//    glVertex3f( -1.0f, -1.0f,  1.0f);  // Bottom-Right of left face
//
//    // Right face
//    //glColor3f(   1.0f,  0.0f,  1.0f);  // Violet
//    glVertex3f(  1.0f,  1.0f,  1.0f);  // Top-Right of left face
//    glVertex3f(  1.0f,  1.0f, -1.0f);  // Top-Left of left face
//    glVertex3f(  1.0f, -1.0f, -1.0f);  // Bottom-Left of left face
//    glVertex3f(  1.0f, -1.0f,  1.0f);  // Bottom-Right of l
//

    glEnd();
    glPopMatrix();
}

