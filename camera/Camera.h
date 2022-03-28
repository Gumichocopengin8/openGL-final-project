//
// Created by Fabien Delattre on 2019-04-19.
//

#ifndef PROJECT_CAMERA_H
#define PROJECT_CAMERA_H

#include "../light/Light.h"

class Camera {
private:
  float pitch; // x rotation
  float yaw; // y rotation
  float roll; // z rotation

public:
  float camera_x;
  float camera_y;
  float camera_z;
  float x_speed;
  float y_speed;
  float z_speed;

  explicit Camera(float camera_x, float camera_y, float camera_z, float pitch, float yaw, float roll);

  void refresh(Light light);

  void move_x(float speed);

  void move_z(float speed);

  void move_y(float speed);

  void lookAt(float diffX, float diffY);

  void idle(float diffX, float diffY);
};


#endif //PROJECT_CAMERA_H
