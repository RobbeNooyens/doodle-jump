//
// Created by robnoo on 25/11/21.
//

#include "PlatformModel.h"
#include "../Settings.h"
#include "../bounding_box/BoundingBox.h"

// Horizontal Platform
// ===================
void models::HorizontalPlatform::update(double elapsed) {
    if(direction == RIGHT) {
        this->x += elapsed*speed;
        double rightX = this->getBoundingBox()->getRight();
        if(rightX >= screenWidth) {
            direction = LEFT;
            this->x -= rightX - screenWidth;
        }
    } else {
        this->x -= elapsed * speed;
        double leftX = this->getBoundingBox()->getLeft();
        if (leftX < 0) {
            direction = RIGHT;
            this->x += leftX;
        }
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
    if(direction == UP) {
        this->y -= elapsed*speed;
        this->relativeY += elapsed*speed;
        if(relativeY >= distance) {
            double difference = relativeY-distance;
            this->y += 2*difference;
            direction = DOWN;
            this->relativeY = 0;
        }
    } else {
        this->y += elapsed * speed;
        this->relativeY += elapsed * speed;
        if (relativeY >= distance) {
            double difference = relativeY - distance;
            this->y += 2 * difference;
            direction = UP;
            this->relativeY = 0;
        }
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
