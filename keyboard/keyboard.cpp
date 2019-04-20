//
// Created by Fabien Delattre on 2019-04-19.
//
#include <iostream>
#include <cstdlib>
#import <GLUT/glut.h>
#include "../main.h"

void keyboard(unsigned char key, int x, int y) {

    if (key == 'a' || key == 'A') exit(0);

    if (key == 'z') {
        cameraPtr->forward(0.2);
    }
    if (key == 's') {
        cameraPtr->backward(0.2);
    }
    if (key == 'd') {
        cameraPtr->right(0.2);
    }
    if (key == 'q') {
        cameraPtr->left(0.2);
    }
    if (key == ' ') {
        cameraPtr->setYSpeed(0.2);
    }

    glutPostRedisplay();



}