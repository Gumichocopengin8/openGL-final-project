//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <iostream>
#include "../camera/Camera.h"


class Player {
    float walking_acceleration;
    float run_speed;
    float vertical_speed;
public:
    Camera camera;

    Player(Camera camera);

    void forward();

    void backward();

    void right();

    void left();

    void run_forward();

    void run_backward();

    void run_right();

    void run_left();

    void jump();

    void down();

    void lookAt(float diffX, float diffY);
};


#endif //PROJECT_PLAYER_H
