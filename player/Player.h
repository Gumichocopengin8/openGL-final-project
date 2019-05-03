//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H

#include <iostream>
#include "../camera/Camera.h"
#include <map>


class Player {
    float walking_acceleration;
    float running_acceleration;
    float vertical_speed;
public:

    std::map<char, bool> keys;
    Camera camera;

    Player(Camera camera);

    void takeAction();

    void forward(bool run);

    void backward(bool run);

    void right(bool run);

    void left(bool run);

    void jump();

    void lookAt(float diffX, float diffY);
};


#endif //PROJECT_PLAYER_H
