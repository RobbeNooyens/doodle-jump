/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "PlatformModel.h"
#include "../Settings.h"
#include "../bounding_box/BoundingBox.h"

models::PlatformModel::PlatformModel(): EntityModel() {}

bool models::PlatformModel::isBeneathScreen() {
    return getBoundingBox()->getTop() > settings::screenHeight;
}

// Horizontal Platform
// ===================
models::HorizontalPlatform::HorizontalPlatform(): PlatformModel(), screenWidth(settings::screenWidth) {}

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
models::TemporaryPlatform::TemporaryPlatform(): PlatformModel() {}

void models::TemporaryPlatform::update(double elapsed) {}

// Vertical Platform
// =================
models::VerticalPlatform::VerticalPlatform(): PlatformModel() {}

void models::VerticalPlatform::update(double elapsed) {
    if(direction == UP) {
        this->y -= elapsed*speed;
        this->relativeY += elapsed*speed;
        if(relativeY >= distance) {
            double difference = relativeY-distance;
            this->y += 2*difference;
            direction = DOWN;
            this->relativeY = distance-difference;
        }
    } else {
        this->y += elapsed * speed;
        this->relativeY -= elapsed * speed;
        if (relativeY <= 0) {
            double difference = -relativeY;
            this->y += 2 * difference;
            direction = UP;
            this->relativeY = difference;
        }
    }
}

bool models::VerticalPlatform::isBeneathScreen() {
    return getBoundingBox()->getTop()-(distance-relativeY) > settings::screenHeight;
}


// Static Platform
// ===============
models::StaticPlatform::StaticPlatform(): PlatformModel() {}

void models::StaticPlatform::update(double elapsed) {}
