//
// Created by robnoo on 25/11/21.
//

#include <algorithm>
#include "PlayerModel.h"
#include "../world/World.h"
#include "../events/HeightChangedEvent.h"
#include "../events/EventManager.h"
#include "../score/ScoreManager.h"
#include "../bounding_box/BoundingBox.h"
#include "../world/Camera.h"
#include "../events/PlayerDiedEvent.h"

void models::PlayerModel::update(double elapsed) {
    double absDifference = elapsed * settings::acceleration;
    int sign = verticalDirection == UP ? -1 : 1;
    this->speed += sign * absDifference;
    this->y += sign * std::min(speed, settings::maxSpeed) * boost * settings::jumpAmplifier;

    updateBoundingBox();

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

    // Detect death
    if(absoluteBBox->getTop() > settings::screenHeight) {
        EventManager::getInstance().invoke(std::make_shared<events::PlayerDiedEvent>());
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
    if(y < settings::maxHeight) {
        double difference = settings::maxHeight - y;
        y = settings::maxHeight;
        ScoreManager::getInstance().addScore(difference);
        EventManager::getInstance().invoke(std::make_shared<events::HeightChangedEvent>(difference));
    }
}

Direction models::PlayerModel::getVerticalDirection() {
    return verticalDirection;
}

Direction models::PlayerModel::getHorizontalDirection() {
    return horizontalDirection;
};
