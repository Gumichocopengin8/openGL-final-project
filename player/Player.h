//
// Created by Fabien Delattre on 2019-04-20.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H


#include "../camera/Camera.h"

class Player {
    float walking_acceleration;
    float walking_speed_max;
    float jumping_speed;
public:
    Camera camera;
    Player(Camera camera);
    void forward();
    void backward();
    void right();
    void left();
    void jump();
    void lookAt(float diffX, float diffY);
};


#endif //PROJECT_PLAYER_H
