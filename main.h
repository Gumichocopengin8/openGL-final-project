//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H
#include "camera/Camera.h"

extern Camera *cameraPtr;

void display();
void reshape(int w, int h);
int main(int argc, char **argv);

#endif //PROJECT_MAIN_H

