//
// Created by Fabien Delattre on 2019-04-19.
//
#include <iostream>
#include <cstdlib>
#import <GLUT/glut.h>

float eyex;
float eyey;
float eyez;

void keyboard(unsigned char key, int x, int y) {

    std::cout << key << std::endl;
    if (key == 's') {
        eyex += 0.2;
        glutPostRedisplay();
    }
    if (key == 'z') {
        eyex -= 0.2;
        glutPostRedisplay();
    }
    if (key == 'r') {
        eyey += 0.2;
        glutPostRedisplay();
    }
    if (key == 'f') {
        eyey -= 0.2;
        glutPostRedisplay();
    }
    if (key == 'd') {
        eyez += 0.2;
        glutPostRedisplay();
    }
    if (key == 'q') {
        eyez -= 0.2;
        glutPostRedisplay();
    }

    if (key == 'a' || key == 'A') exit(0);

}