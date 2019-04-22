//
// Created by Keita Nonaka on 2019-04-20.
//

#include "Texture.h"

Texture::Texture() {
    mat_ambient[] = { 0.0 , 0.0 , 0.0 , 0.0 };
    mat_diffuse[] = { 0.0 , 0.0 , 0.0 , 0.0 };
    mat_specular[] = { 0.0 , 0.0 , 0.0 , 0.0 };
    mat_shininess[] = { 0 };
}

void Texture::apply() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void Texture::grass() {
    mat_ambient[0] = 0;
    mat_ambient[1] = 0.223529;
    mat_ambient[2] = 0.027451;

    mat_diffuse[0] = 0;
    mat_diffuse[1] = 0.568627;
    mat_diffuse[2] = 0.113725;
    mat_specular[0] = 0.992157;
    mat_specular[1] = 0.941176;
    mat_specular[2] = 0.807843;

    mat_shininess[0] = 27.9;
    this->apply();
}

void Texture::treeTrunk() {
    mat_ambient[0] = 0.467;
    mat_ambient[1] = 0.35686;
    mat_ambient[2] = 0.25882;

    mat_diffuse[0] = 0.467;
    mat_diffuse[1] = 0.35686;
    mat_diffuse[2] = 0.25882;

    mat_specular[0] = 0;
    mat_specular[1] = 0.05;
    mat_specular[2] = 0;

    mat_shininess[0] = 30;
    this->apply();
}

void Texture::treeLeaves() {
    mat_ambient[0] = 0.467;
    mat_ambient[1] = 0.35686;
    mat_ambient[2] = 0.25882;

    mat_diffuse[0] = 0;
    mat_diffuse[1] = 0.55686;
    mat_diffuse[2] = 0.25882;

    mat_specular[0] = 0.2;
    mat_specular[1] = 0.2;
    mat_specular[2] = 0;

    mat_shininess[0] = 30;
    this->apply();
}


void Texture::ground() {
    mat_ambient[0] = 0.2125;
    mat_ambient[1] = 0.1275;
    mat_ambient[2] = 0.054;

    mat_diffuse[0] = 0.714;
    mat_diffuse[1] = 0.4284;
    mat_diffuse[2] = 0.18144;

    mat_specular[0] = 0.393548;
    mat_specular[1] = 0.271906;
    mat_specular[2] = 0.166721;

    mat_shininess[0] = 25.6;
    this->apply();
}
