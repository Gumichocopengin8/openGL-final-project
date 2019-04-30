//
// Created by Keita Nonaka on 2019-04-28.
//

#include <GLUT/glut.h>
#include "Light.h"

Light::Light() {
    for(int i = 0; i < 4; i++) {
        diffuse[i] = 1.0;
        specular[i] = 1.0;
        ambient[i] = 0.25;
    }
    position[0] = 50.0;
    position[1] = 40.0;
    position[2] = 100.0;
    position[3] = 0.0;

    spotDirrection[0] = 50;
    spotDirrection[1] = 10.0;
    spotDirrection[2] = 10;
}

void Light::ApplyLight() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0 , GL_POSITION , this->diffuse);
    glLightfv(GL_LIGHT0 , GL_DIFFUSE , this->specular);
    glLightfv(GL_LIGHT0 , GL_AMBIENT , this->ambient);
    glLightfv(GL_LIGHT0 , GL_SPECULAR , this->position);
    glLightfv( GL_LIGHT0, GL_SPOT_DIRECTION, spotDirrection );
    glutSwapBuffers();
}

