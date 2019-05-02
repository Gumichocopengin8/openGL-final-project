//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <iostream>
#include "../camera/Camera.h"


class Player {
    float walking_acceleration;
    float vertical_speed;
public:
    Camera camera;

    Player(Camera camera);

    void forward();

    void backward();

    void right();

    void left();

    void jump();

    void down();

    void lookAt(float diffX, float diffY);
};


#endif //PROJECT_PLAYER_H
