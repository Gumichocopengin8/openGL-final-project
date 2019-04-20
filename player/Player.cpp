//
// Created by Fabien Delattre on 2019-04-20.
//

#include "Player.h"

Player::Player(Camera camera) : camera(camera) {
    this->walking_speed = 0.2;
    this->jumping_speed = 0.2;
}

void Player::forward() {
    this->camera.move_x(-this->walking_speed);
}

void Player::backward() {
    this->camera.move_x(this->walking_speed);
}

void Player::right() {
    this->camera.move_z(-this->walking_speed);
}

void Player::left() {
    this->camera.move_z(this->walking_speed);
}

void Player::jump() {
    this->camera.move_y(0.2);
}

void Player::lookAt(float diffX, float diffY) {
    this->camera.lookAt(diffX, diffY);
}