//
// Created by Fabien Delattre on 2019-04-19.
//

#include "Window.h"


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
