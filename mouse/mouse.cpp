//
// Created by Fabien Delattre on 2019-04-19.
//
#include <cstdlib>
#import <GLUT/glut.h>

void mouse(GLint btn, GLint state, GLint x, GLint y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutPostRedisplay();
    }

    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        exit(0);
    }
}