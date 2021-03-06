//
// Created by Keita Nonaka on 2019-04-28.
//

#include <GLUT/glut.h>
#include "Light.h"

Light::Light() {
    for (int i = 0; i < 4; i++) {
        this->diffuse[i] = 0.3;
        this->specular[i] = 1.3;
        this->ambient[i] = 0.65;
    }
    this->position[0] = 0.0;
    this->position[1] = 0.0;
    this->position[2] = 0.0;
    this->position[3] = 1.0;

    this->spotDirection[0] = 0;
    this->spotDirection[1] = 0.0;
    this->spotDirection[2] = 0;
}

void Light::ApplyLight() {


    glLightfv(GL_LIGHT0, GL_DIFFUSE, this->diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, this->ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, this->specular);
    glutSwapBuffers();
}
