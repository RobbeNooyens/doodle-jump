//
// Created by robnoo on 25/11/21.
//

#include <algorithm>
#include "PlayerModel.h"
#include "../World.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../events/EventManager.h"
#include "../ScoreManager.h"
#include "../bounding_box/BoundingBox.h"
#include "../Camera.h"

void models::PlayerModel::update(double elapsed) {
    auto previousBottom = this->getBoundingBox()->getBottom();

    double absDifference = elapsed * settings::acceleration;
    int sign = verticalDirection == UP ? -1 : 1;
    this->speed += sign * absDifference;
    this->y += sign * std::min(speed, settings::maxSpeed) * boost * settings::jumpAmplifier;

    updateBoundingBox();

    World::getInstance().checkCollisions(previousBottom);

    if(speed < 0) {
        verticalDirection = DOWN;
        speed = 0;
        boost = 1;
    }

    // Update boost
    if(boost < 1) {
        boost *= (1+elapsed);
    } else if(boost > 1) {
        boost /= (1+elapsed);
    }

    checkMaxHeight();

    // Left right
    if(moveXAxis) {
        if(horizontalDirection == LEFT) {
            this->x -= 300*(elapsed);
        } else if(horizontalDirection == RIGHT) {
            this->x += 300*(elapsed);
        }
    }
    moveXAxis = false;

    // Detect off-screen
    if(getBoundingBox()->getRight() < 0) {
        this->x = settings::screenWidth + getBoundingBox()->getWidth()/2;
    } else if(getBoundingBox()->getLeft() > settings::screenWidth) {
        this->x = -getBoundingBox()->getWidth()/2;
    }
}

models::PlayerModel::PlayerModel(): EntityModel() {}

void models::PlayerModel::bounce(double from) {
    verticalDirection = UP;
    double difference = this->getBoundingBox()->getBottom() - from;
    this->y -= difference;
    this->speed = 10;
}

void models::PlayerModel::moveHorizontal(Direction direction) {
    horizontalDirection = direction;
    moveXAxis = true;
}

void models::PlayerModel::useBonus(BonusType bonusType, double surfaceHeight) {
    Direction previousDirection = verticalDirection;
    bounce(surfaceHeight);
    if(bonusType == BonusType::SPRING) {
        boost = 5;
    } else if(bonusType == BonusType::JETPACK) {
        if(previousDirection == DOWN)
            boost = 0.5;
        speed = 40;
    }
}

void models::PlayerModel::bounceOnPlatform(double surfaceHeight) {
    bounce(surfaceHeight);
}

void models::PlayerModel::checkMaxHeight() {
    if(y <= settings::maxHeight) {
        double difference = settings::maxHeight - y;
        y = settings::maxHeight;
        ScoreManager::getInstance().addScore(difference);
        Camera::getInstance().addHeight(difference);
        std::shared_ptr<Event> newHeight = std::make_shared<ReachedNewHeightEvent>(difference, Camera::getInstance().getHeight());
        EventManager::getInstance().invoke(newHeight);
    }
};
