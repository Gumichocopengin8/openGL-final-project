//
// Created by Fabien Delattre on 2019-04-19.
//
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>
#include "Camera.h"
#include "../main.h"


#define WALKING_SPEED 0.3
#define GRAVITY 0.05


Camera::Camera(double camera_x, double camera_y, double camera_z, double pitch, double yaw, double roll) {
    this->camera_x = camera_x;
    this->camera_y = camera_y;
    this->camera_z = camera_z;
    this->pitch = pitch;
    this->yaw = yaw;
    this->roll = roll;
    this->y_speed = 0;
}

void Camera::refresh() {


    // Y position update
    this->camera_y += this->y_speed;

    this->y_speed -= GRAVITY;

    if (this->camera_y < 2) {
        this->camera_y = 2;
    }


    // transformations update
    gluLookAt(0, 0, 0, 0, 0, 1, 0, 1, 0);
    glRotatef(this->pitch * 57.2958, 1.0f, 0.0f, 0.0f);
    glRotatef(this->yaw * 57.2958, 0.0f, 1.0f, 0.0f);
    glRotatef(this->roll * 57.2958, 0.0f, 0.0f, 1.0f);
    glTranslatef(-this->camera_x, -this->camera_y, -this->camera_z);
}

/**
Maths:

cp = cos(φ); sp = sin(φ);
cy = cos(θ); sy = sin(θ);

f: <  sy*cp, sp, -cy*cp >
r: <  cy   ,  0,  sy    >
u: < -sy*sp, cp,  cy*sp >
 **/

void Camera::forward(float diff) {
    this->camera_x -= sin(this->yaw) * cos(this->pitch) * WALKING_SPEED;
    this->camera_z -= -cos(this->yaw) * cos(this->pitch) * WALKING_SPEED;
    glutPostRedisplay();
}

void Camera::backward(float diff) {
    this->camera_x += sin(this->yaw) * cos(this->pitch) * WALKING_SPEED;
    this->camera_z += -cos(this->yaw) * cos(this->pitch) * WALKING_SPEED;
    glutPostRedisplay();
}

void Camera::left(float diff) {
    this->camera_x += cos(this->yaw) * WALKING_SPEED;
    this->camera_z += sin(this->yaw) * WALKING_SPEED;
    glutPostRedisplay();
}

void Camera::right(float diff) {
    this->camera_x -= cos(this->yaw) * WALKING_SPEED;
    this->camera_z -= sin(this->yaw) * WALKING_SPEED;
    glutPostRedisplay();
}

void Camera::lookAt(float diffX, float diffY) {

    this->pitch = -diffY * 1.7 / windowPtr->getHeight();
    this->yaw = diffX * 6 / windowPtr->getWidth();
    glutPostRedisplay();
}

void Camera::idle(float diffX, float diffY) {
    this->pitch += diffX / 6000;
    this->yaw += diffY / 6000;
    glutPostRedisplay();
}

void Camera::jump() {
    y_speed = 0.5;
}



