//
// Created by Fabien Delattre on 2019-04-19.
//
#include <GLUT/glut.h>
#include <math.h>
#include "Camera.h"


Camera::Camera(double camera_x, double camera_y, double camera_z, double pitch, double yaw, double roll) {
    this->camera_x = camera_x;
    this->camera_y = camera_y;
    this->camera_z = camera_z;
    this->pitch = pitch;
    this->yaw = yaw;
    this->roll = roll;
}

void Camera::refresh() {
    gluLookAt(0, 0, 0, 0, 0, 1, 0, 1, 0);
    glRotatef(this->pitch*57.2958, 1.0f, 0.0f, 0.0f);
    glRotatef(this->yaw*57.2958, 0.0f, 1.0f, 0.0f);
    glRotatef(this->roll*57.2958, 0.0f, 0.0f, 1.0f);
    glTranslatef(-this->camera_x, -this->camera_y, -this->camera_z);
}

//cp = cos(φ); sp = sin(φ);
//cy = cos(θ); sy = sin(θ);
//
//f: <  sy*cp, sp, -cy*cp >
//r: <  cy   ,  0,  sy    >
//u: < -sy*sp, cp,  cy*sp >



void Camera::forward(float diff) {
    this->camera_x -= sin(this->yaw)*cos(this->pitch)*0.1;
    //this->camera_y += sin(this->pitch)*0.1;
    this->camera_z -= -cos(this->yaw)*cos(this->pitch)*0.1;
    glutPostRedisplay();
}

void Camera::backward(float diff) {
    this->camera_x += sin(this->yaw)*cos(this->pitch)*0.1;
    //this->camera_y -= sin(this->pitch)*0.1;
    this->camera_z += -cos(this->yaw)*cos(this->pitch)*0.1;
    glutPostRedisplay();
}

void Camera::left(float diff) {
    this->camera_x += cos(this->yaw)*0.1;
    this->camera_z += sin(this->yaw)*0.1;
    glutPostRedisplay();
}

void Camera::right(float diff) {
    this->camera_x -= cos(this->yaw)*0.1;
    this->camera_z -= sin(this->yaw)*0.1;
    glutPostRedisplay();
}

void Camera::lookAt(float diffX, float diffY) {

    this->pitch = -diffY*1.56/200;
    this->yaw = diffX*6/200;
    glutPostRedisplay();
}



