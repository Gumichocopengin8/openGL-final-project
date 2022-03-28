//
// Created by Fabien Delattre on 2019-04-19.
//

#include "Window.h"

Window::Window(int default_width, int default_height) {
  this->default_width = default_width;
  this->width = this->default_width;

  this->default_height = default_height;
  this->height = this->default_height;
}

void Window::setWidth(int widthValue) {
  Window::width = widthValue;
}


void Window::setHeight(int heightValue) {
  Window::height = heightValue;
}

int Window::getWidth() const {
  return width;
}

int Window::getHeight() const {
  return height;
}
