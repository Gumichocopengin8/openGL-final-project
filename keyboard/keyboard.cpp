//
// Created by Fabien Delattre on 2019-04-19.
//
#include "keyboard.h"

#include <cstdlib>
#include <iostream>
#import <GLUT/glut.h>


void keydown(unsigned char key, int x, int y) {
    std::cout << key << std::endl;
    switch (key) {
        case 'q':
        case 'Q':
            exit(0);
        default:
            playerPtr->keys[key] = true;

    }
}

void keyup(unsigned char key, int x, int y) {

    playerPtr->keys[key] = false;
}

