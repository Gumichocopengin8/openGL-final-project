//
// Created by Fabien Delattre on 2019-04-19.
//

#include "Camera.h"

#include "../main.h"

#include <iostream>
#include <math.h>
#include <GLUT/glut.h>

using namespace std;


#define GRAVITY 0.02
#define MAX_SPEED 2.5
#define GROUND_FRICTION 0.19

Camera::Camera(double camera_x, double camera_y, double camera_z, double pitch, double yaw, double roll) {
    this->camera_x = camera_x;
    this->camera_y = camera_y;
    this->camera_z = camera_z;
    this->pitch = pitch;
    this->yaw = yaw;
    this->roll = roll;
    this->x_speed = 0;
    this->y_speed = 0;
    this->z_speed = 0;
}

void Camera::refresh(Light light) {

    // transformations update
    gluLookAt(0, 0, 0, 0, 0, 1, 0, 1, 0);
    glRotatef(this->pitch * 57.2958, 1.0f, 0.0f, 0.0f);
    glRotatef(this->yaw * 57.2958, 0.0f, 1.0f, 0.0f);
    glRotatef(this->roll * 57.2958, 0.0f, 0.0f, 1.0f);
    glTranslatef(-this->camera_x, -this->camera_y, -this->camera_z);
    light.position[0] = this->camera_x;
    light.position[1] = this->camera_y;
    light.position[2] = this->camera_z;
    glLightfv(GL_LIGHT0, GL_POSITION, light.position);
    // speed update

    this->move_x(this->x_speed * -GROUND_FRICTION);
    this->move_y(this->y_speed * -GROUND_FRICTION);
    //this->move_y(-GRAVITY);
    this->move_z(this->z_speed * -GROUND_FRICTION);
}

/**
Maths:

cp = cos(φ); sp = sin(φ);
cy = cos(θ); sy = sin(θ);

f: <  sy*cp, sp, -cy*cp >
r: <  cy   ,  0,  sy    >
u: < -sy*sp, cp,  cy*sp >
 **/

void Camera::move_x(float speed) {

    this->x_speed += speed;

    if (this->x_speed > MAX_SPEED) this->x_speed = MAX_SPEED;


    double new_camera_x = this->camera_x + sin(this->yaw) * cos(this->pitch) * this->x_speed;
    double new_camera_y = this->camera_y + sin(this->pitch) * speed;
    double new_camera_z = this->camera_z - cos(this->yaw) * cos(this->pitch) * this->x_speed;


    this->camera_x = new_camera_x;
    this->camera_y = new_camera_y;
    this->camera_z = new_camera_z;


}


void Camera::move_z(float speed) {

    this->z_speed += speed;

    if (this->z_speed > MAX_SPEED) this->z_speed = MAX_SPEED;

    double new_camera_x = this->camera_x + cos(this->yaw) * this->z_speed;
    double new_camera_z = this->camera_z + sin(this->yaw) * this->z_speed;

    this->camera_x = new_camera_x;
    this->camera_z = new_camera_z;
}

void Camera::move_y(float speed) {

    this->y_speed += speed;
    if (this->y_speed > MAX_SPEED) this->y_speed = MAX_SPEED;

    double new_camera_y = this->camera_y + cos(this->pitch) * this->y_speed;

    this->camera_y = new_camera_y;


}

void Camera::lookAt(float diffX, float diffY) {

    this->pitch = -diffY * 1.7 / windowPtr->getHeight();
    this->yaw = diffX * 6 / windowPtr->getWidth();
}

void Camera::idle(float diffX, float diffY) {
    this->pitch += diffX / 6000;
    this->yaw += diffY / 6000;
}



