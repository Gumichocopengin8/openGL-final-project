//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_MOUSE_H
#define PROJECT_MOUSE_H

#import "../main.h"

#include <cstdlib>
#include <iostream>
#import <GLUT/glut.h>

void mouse(GLint btn, GLint state, GLint x, GLint y);

void mouseMotion(int x, int y);

#endif //PROJECT_MOUSE_H
