//
// Created by Fabien Delattre on 2019-04-19.
//
#include "keyboard.h"

#include <cstdlib>
#include <iostream>
#import <GLUT/glut.h>

void keyboard(unsigned char key, int x, int y) {

    if (key == 'a' || key == 'A') exit(0);

    if (key == 'z') {
        playerPtr->forward();
    }
    if (key == 's') {
        playerPtr->backward();
    }
    if (key == 'd') {
        playerPtr->right();
    }
    if (key == 'q') {
        playerPtr->left();
    }
    if (key == ' ') {
        playerPtr->jump();
    }

    glutPostRedisplay();


}