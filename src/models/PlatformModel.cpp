//
// Created by robnoo on 25/11/21.
//

#include "PlatformModel.h"
#include "../Settings.h"

// Horizontal Platform
// ===================
void models::HorizontalPlatform::update(double elapsed) {
    if(direction == RIGHT) {
        this->x += elapsed*speed;
        double rightX = this->getBox().second.first;
        if(rightX >= screenWidth) {
            direction = LEFT;
            this->x -= rightX - screenWidth;
        }
    } else if(direction == LEFT) {
        this->x -= elapsed*speed;
        double leftX = this->getBox().first.first;
        if(leftX < 0) {
            direction = RIGHT;
            this->x += leftX;
        }
    } else {
        throw std::runtime_error("Cant have another value");
    }
}

models::HorizontalPlatform::HorizontalPlatform(): PlatformModel(), screenWidth(settings::screenWidth) {

}

// Temporary Platform
// ==================
void models::TemporaryPlatform::update(double elapsed) {
}

models::TemporaryPlatform::TemporaryPlatform(): PlatformModel() {

}

// Vertical Platform
// =================
void models::VerticalPlatform::update(double elapsed) {
    if(direction == RIGHT) {
        this->x += elapsed*speed;
        double rightX = this->getBox().second.first;
        if(rightX >= 10) {
            direction = LEFT;
            this->x -= rightX - 10;
        }
    } else if(direction == LEFT) {
        this->x -= elapsed*speed;
        double leftX = this->getBox().first.first;
        if(leftX < 0) {
            direction = RIGHT;
            this->x += leftX;
        }
    } else {
        throw std::runtime_error("Cant have another value");
    }
}

models::VerticalPlatform::VerticalPlatform(): PlatformModel() {

}

models::PlatformModel::PlatformModel(): EntityModel() {

}

// Static Platform
// ===============
void models::StaticPlatform::update(double elapsed) {

}

models::StaticPlatform::StaticPlatform(): PlatformModel() {

}
