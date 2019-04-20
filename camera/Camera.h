//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_CAMERA_H
#define PROJECT_CAMERA_H


class Camera {
private:
    double camera_x;
    double camera_y;
    double camera_z;
    double pitch; // x rotation
    double yaw; // y rotation
    double roll; // z rotation
    double y_speed;
public:
    Camera(double camera_x, double camera_y, double camera_z, double pitch, double yaw, double roll);
    void refresh();
    void forward(float diff);
    void backward(float diff);
    void left(float diff);
    void right(float diff);
    void lookAt(float diffX, float diffY);
    void idle(float diffX, float diffY);
    void jump();

};


#endif //PROJECT_CAMERA_H
