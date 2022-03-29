//
// Created by Fabien Delattre on 2019-04-19.
//
#include "mouse.h"

namespace {
  int lastx = -1;
  int lasty = -1;
}

void mouse(GLint btn, GLint state, GLint x, GLint y) {
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    glutPostRedisplay();

  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    exit(0);
}

void mouseMotion(int x, int y) {
  if (lastx == -1 || x < 0 || y < 0) {
    lastx = x;
  }
  lastx = x;
  playerPtr->lookAt(x - 200, y - 200);
}
