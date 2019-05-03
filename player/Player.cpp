//
// Created by Fabien Delattre on 2019-04-20.
//

#include "Player.h"
#include "../main.h"
#include <cmath>

#include "../keyboard/keyboard.h"

using namespace std;

Player::Player(Camera camera) : camera(camera) {
    this->walking_acceleration = 0.07;
    this->running_acceleration = 0.12;
    this->vertical_speed = 0.3;
}

void Player::forward(bool run) {
    this->camera.move_x(-this->walking_acceleration);
}

void Player::backward(bool run) {
    this->camera.move_x(this->walking_acceleration);
}

void Player::right(bool run) {
    this->camera.move_z(-this->walking_acceleration);
}

void Player::left(bool run) {
    this->camera.move_z(this->walking_acceleration);
}

void Player::jump() {
    if (abs(this->camera.y_speed) < 0.01)this->camera.move_y(this->vertical_speed);
}

void Player::lookAt(float diffX, float diffY) {
    this->camera.lookAt(diffX, diffY);
}

void Player::takeAction() {
    if (this->keys['w']) {
        playerPtr->forward(false);
    }

    if (this->keys['W']) {
        playerPtr->forward(true);
    }

    if (this->keys['s']) {
        playerPtr->backward(false);
    }

    if (this->keys['S']) {
        playerPtr->backward(true);
    }

    if (this->keys['a']) {
        playerPtr->left(false);
    }

    if (this->keys['A']) {
        playerPtr->left(true);
    }


    if (this->keys['d']) {
        playerPtr->right(false);
    }

    if (this->keys['D']) {
        playerPtr->right(true);
    }

    if (this->keys[' ']) {
        playerPtr->jump();
    }
}
