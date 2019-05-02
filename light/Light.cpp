//
// Created by Keita Nonaka on 2019-04-28.
//

#include <GLUT/glut.h>
#include "Light.h"

Light::Light() {
    for(int i = 0; i < 4; i++) {
        this->diffuse[i] = 1.0;
        this->specular[i] = 1.0;
        this->ambient[i] = 2.25;
    }
    this->position[0] = 50.0;
    this->position[1] = 40.0;
    this->position[2] = 10.0;
    this->position[3] = 0.0;

    this->spotDirection[0] = 0;
    this->spotDirection[1] = 0.0;
    this->spotDirection[2] = 0;
}

void Light::ApplyLight() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0 , GL_POSITION , this->position);
    glLightfv(GL_LIGHT0 , GL_DIFFUSE , this->diffuse);
    glLightfv(GL_LIGHT0 , GL_AMBIENT , this->ambient);
    glLightfv(GL_LIGHT0 , GL_SPECULAR , this->specular);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, this->spotDirection);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10);
    glutSwapBuffers();
}

