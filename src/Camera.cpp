//
// Created by robbe on 20/11/2021.
//

#include "Camera.h"

Camera &Camera::getInstance() {
    static Camera INSTANCE;
    return INSTANCE;
}

double Camera::getHeight() const {
    return height;
}

void Camera::setHeight(double h) {
    this->height = h;
}

void Camera::addHeight(double h) {
    this->height += h;
}

Camera::Camera() = default;
