//
// Created by Keita Nonaka on 2019-04-20.
//

#include <GLUT/glut.h>
#include "Texture.h"

Texture::Texture() {
    for (int i = 0; i < 4; i++) {
        this->ambient[i] = 0.0;
        this->diffuse[i] = 0.0;
        this->specular[i] = 0.0;
    }
    this->shininess[0] = 0;
}

void Texture::apply() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, this->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, this->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, this->specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, this->shininess);
}


void Texture::ground() {
    this->ambient[0] = 0.2125;
    this->ambient[1] = 0.1275;
    this->ambient[2] = 0.054;

    this->diffuse[0] = 0.714;
    this->diffuse[1] = 0.4284;
    this->diffuse[2] = 0.18144;

    this->specular[0] = 0.001;
    this->specular[1] = 0.001;
    this->specular[2] = 0.001;

    this->shininess[0] = 100;
    this->apply();
}

void Texture::grass() {
    this->ambient[0] = 0;
    this->ambient[1] = 0.223529;
    this->ambient[2] = 0.027451;

    this->diffuse[0] = 0.6;
    this->diffuse[1] = 0.6568627;
    this->diffuse[2] = 0.6113725;

    this->specular[0] = 0.092157;
    this->specular[1] = 0.041176;
    this->specular[2] = 0.007843;

    this->shininess[0] = 27.9;
    this->apply();
}

void Texture::treeTrunk() {
    this->ambient[0] = 0.467;
    this->ambient[1] = 0.35686;
    this->ambient[2] = 0.25882;

    this->diffuse[0] = 0.467;
    this->diffuse[1] = 0.35686;
    this->diffuse[2] = 0.25882;

    this->specular[0] = 0;
    this->specular[1] = 0.05;
    this->specular[2] = 0;

    this->shininess[0] = 30;
    this->apply();
}

void Texture::treeLeaves() {
    this->ambient[0] = 0.467;
    this->ambient[1] = 0.35686;
    this->ambient[2] = 0.25882;

    this->diffuse[0] = 0;
    this->diffuse[1] = 0.55686;
    this->diffuse[2] = 0.25882;

    this->specular[0] = 0.2;
    this->specular[1] = 0.2;
    this->specular[2] = 0;

    this->shininess[0] = 30;
    this->apply();
}

void Texture::snow() {
    this->ambient[0] = 1;
    this->ambient[1] = 1;
    this->ambient[2] = 1;

    this->diffuse[0] = 0;
    this->diffuse[1] = 1;
    this->diffuse[2] = 1;

    this->specular[0] = 0.2;
    this->specular[1] = 0.2;
    this->specular[2] = 0;

    this->shininess[0] = 30;
    this->apply();
}

void Texture::water() {
    this->ambient[0] = 0;
    this->ambient[1] = 0.35686;
    this->ambient[2] = 0.85882;

    this->diffuse[0] = 0;
    this->diffuse[1] = 0.55686;
    this->diffuse[2] = 0.85882;

    this->specular[0] = 0.2;
    this->specular[1] = 0.2;
    this->specular[2] = 0;

    this->shininess[0] = 30;
    this->apply();
}

void Texture::cloud() {
    this->ambient[0] = 0.75686;
    this->ambient[1] = 0.75686;
    this->ambient[2] = 0.75686;

    this->diffuse[0] = 0.75686;
    this->diffuse[1] = 0.75686;
    this->diffuse[2] = 0.75686;

    this->specular[0] = 0.2;
    this->specular[1] = 0.2;
    this->specular[2] = 0;

    this->shininess[0] = 30;
    this->apply();
}
