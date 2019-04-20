//
// Created by Fabien Delattre on 2019-04-19.
//
#include <iostream>
#include <cstdlib>
#import <GLUT/glut.h>
#include "../main.h"

int lastx = -1;
int lasty = -1;

void mouse(GLint btn, GLint state, GLint x, GLint y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutPostRedisplay();
    }

    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        exit(0);
    }
}

void mouseMotion(int x, int y) {
    //std::cout << x << " " << y << std::endl;
    if(lastx == -1 || x < 0 || y < 0) {
        lastx = x;
        lasty = y;
    }
    int diffx = x - lastx;
    int diffy = y - lasty;
    lastx = x;
    lasty = y;
    cameraPtr->lookAt(x-200, y-200);
//    xrot += (float) diffy;
//    yrot += (float) diffx;
}