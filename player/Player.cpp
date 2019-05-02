//
// Created by Fabien Delattre on 2019-04-20.
//

#include "Player.h"
#include "../main.h"
using namespace std;

Player::Player(Camera camera) : camera(camera) {
    this->walking_acceleration = 0.07;
    this->walking_speed_max = 2;
    this->jumping_speed = 0.3;
}

void Player::forward() {

    this->camera.move_x(-this->walking_acceleration);
}

void Player::backward() {
    this->camera.move_x(this->walking_acceleration);
}

void Player::right() {
    this->camera.move_z(-this->walking_acceleration);
}

void Player::left() {
    this->camera.move_z(this->walking_acceleration);
}

void Player::jump() {
    this->camera.move_y(this->jumping_speed);
}

void Player::lookAt(float diffX, float diffY) {
    this->camera.lookAt(diffX, diffY);
}
