//
// Created by Keita Nonaka on 2019-04-28.
//

#include <GLUT/glut.h>
#include "Light.h"

Light::Light() {}

void Light::ApplyLight() {
  glLightfv(GL_LIGHT0, GL_DIFFUSE, this->diffuse);
  glLightfv(GL_LIGHT0, GL_AMBIENT, this->ambient);
  glLightfv(GL_LIGHT0, GL_SPECULAR, this->specular);
  glutSwapBuffers();
}
