//
// Created by Fabien Delattre on 2019-04-19.
//
#include "keyboard.h"

#include <cstdlib>
#include <iostream>
#import <GLUT/glut.h>

void keyboard(unsigned char key, int x, int y) {

    if (key == 'q' || key == 'Q') exit(0);

    if (key == 'w') playerPtr->forward();
    if (key == 's') playerPtr->backward();
    if (key == 'd') playerPtr->right();
    if (key == 'a') playerPtr->left();
    if (key == ' ') playerPtr->jump();
    if (key == 'y') playerPtr->down();

    glutPostRedisplay();
}
