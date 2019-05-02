//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_CAMERA_H
#define PROJECT_CAMERA_H

#include "../light/Light.h"

class Camera {
private:
    double pitch; // x rotation
    double yaw; // y rotation
    double roll; // z rotation

public:
    double camera_x;
    double camera_y;
    double camera_z;
    double x_speed;
    double y_speed;
    double z_speed;

    Camera(double camera_x, double camera_y, double camera_z, double pitch, double yaw, double roll);

    void refresh(Light light);

    void move_x(float speed);

    void move_z(float speed);

    void move_y(float speed);

    void lookAt(float diffX, float diffY);

    void idle(float diffX, float diffY);


};


#endif //PROJECT_CAMERA_H
