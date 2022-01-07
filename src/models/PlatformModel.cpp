//
// Created by robnoo on 25/11/21.
//

#include "PlatformModel.h"
#include "../Settings.h"
#include "../bounding_box/BoundingBox.h"

models::PlatformModel::PlatformModel(std::shared_ptr<EntityController>& controller): EntityModel(controller) {}

// Horizontal Platform
// ===================
models::HorizontalPlatform::HorizontalPlatform(std::shared_ptr<EntityController> controller): PlatformModel(controller), screenWidth(settings::screenWidth) {}

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

// Temporary Platform
// ==================
models::TemporaryPlatform::TemporaryPlatform(std::shared_ptr<EntityController> controller): PlatformModel(controller) {}

void models::TemporaryPlatform::update(double elapsed) {}

// Vertical Platform
// =================
models::VerticalPlatform::VerticalPlatform(std::shared_ptr<EntityController> controller): PlatformModel(controller) {}

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


// Static Platform
// ===============
models::StaticPlatform::StaticPlatform(std::shared_ptr<EntityController> controller): PlatformModel(controller) {}

void models::StaticPlatform::update(double elapsed) {}
