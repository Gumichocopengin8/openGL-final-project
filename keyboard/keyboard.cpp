//
// Created by Fabien Delattre on 2019-04-19.
//
#include "keyboard.h"

#include <cstdlib>
#include <iostream>
#import <GLUT/glut.h>

void keyboard(unsigned char key, int x, int y) {

    switch (key) {
        case 'q':
        case 'Q':
            exit(0);
            break;
        case 'w':
            playerPtr->forward();
            break;
        case 'W':
            playerPtr->run_forward();
            break;
        case 's':
            playerPtr->backward();
            break;
        case 'S':
            playerPtr->run_backward();
            break;
        case 'd':
            playerPtr->right();
            break;
        case 'D':
            playerPtr->run_right();
            break;
        case 'a':
            playerPtr->left();
            break;
        case 'A':
            playerPtr->run_left();
            break;
        case ' ':
            playerPtr->jump();
            break;
        case 'x':
            playerPtr->down();
            break;
    }

    glutPostRedisplay();
}
