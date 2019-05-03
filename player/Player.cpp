//
// Created by Fabien Delattre on 2019-04-20.
//

#include "Player.h"
#include "../main.h"
#include <cmath>

using namespace std;

Player::Player(Camera camera) : camera(camera) {
    this->walking_acceleration = 0.07;
    this->run_speed = 1;
    this->vertical_speed = 0.3;
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

void Player::run_forward() {
    this->camera.move_x(-this->run_speed);
}

void Player::run_backward() {
    this->camera.move_x(this->run_speed);
}

void Player::run_right() {
    this->camera.move_z(-this->run_speed);
}

void Player::run_left() {
    this->camera.move_z(this->run_speed);
}

void Player::jump() {
    if(abs(this->camera.y_speed) < 0.01)this->camera.move_y(this->vertical_speed);
}

void Player::down() {
    this->camera.move_y(-this->vertical_speed);
}

void Player::lookAt(float diffX, float diffY) {
    this->camera.lookAt(diffX, diffY);
}
