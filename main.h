//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H
#include "player/Player.h"
#include "window/Window.h"

extern Window *windowPtr;
extern Player *playerPtr;

void display();
void reshape(int w, int h);
int main(int argc, char **argv);

#endif //PROJECT_MAIN_H

