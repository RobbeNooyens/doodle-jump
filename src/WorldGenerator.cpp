//
// Created by robnoo on 4/12/21.
//

#include <iostream>
#include "WorldGenerator.h"
#include "events/ReachedNewHeightEvent.h"
#include "World.h"
#include "ScoreManager.h"
#include "utils/Random.h"
#include "factories/ConcreteFactory.h"
#include "Settings.h"
#include "bounding_box/BoundingBox.h"
#include "Camera.h"

void WorldGenerator::update() {
    while(ScoreManager::getInstance().getScore() >= nextHeight) {
        generatePlatform();
        calculateNextPlatformHeight();
    }
}

void WorldGenerator::generatePlatform() {
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(nextPlatformType);
    auto midX = platform->getBoundingBox()->getWidth()/2;
    auto midY = platform->getBoundingBox()->getHeight()/2;
    auto platformX = Random::getInstance().generate<double>(midX, settings::screenWidth-midX);
    auto platformY = -midY+(ScoreManager::getInstance().getScore()-nextHeight);
    platform->moveTo(platformX, platformY);
    World::getInstance().addPlatform(platform);
    if(addBonus) {
        std::shared_ptr<controllers::BonusController> bonusController = factory->loadBonus(bonusType);
        bonusController->setPlatform(platform);
//        bonusController->attachTo(platform);
//        bonusController->syncWithPlatform();
        World::getInstance().addBonus(bonusController);
    }
}

void WorldGenerator::calculateNextPlatformHeight() {
    double height = Camera::getInstance().getHeight();
    double difficulty = std::min(height / 20000.0, 1.0);
    double intervalBegin = difficulty/2;
    double intervalEnd = difficulty + 0.5;
    int yRelative = (int) (Random::getInstance().generate(intervalBegin, intervalEnd) * heightDifference);
    previousHeight = nextHeight;
    nextHeight = previousHeight + (minHeight + yRelative);
    std::map<double, PlatformType> types = {{1, STATIC}};
    if(height > 1000) {
        types.emplace(0.5, HORIZONTAL);
    }
    if(height > 5000) {
        types.emplace(0.2, TEMPORARY);
    }
    if(height > 10000) {
        types.emplace(0.1, VERTICAL);
    }
    nextPlatformType = Random::getInstance().randomWeighted(types);
    // Decide whether or not to include a bonus
    addBonus = Random::getInstance().generate<double>() <= 0.2;
    if(addBonus && height > 500 && nextPlatformType != TEMPORARY) {
        std::map<double, BonusType> bonuses;
        if(height > 500) {
            bonuses.emplace(1, SPRING);
        }
        if(height > 1500) {
            bonuses.emplace(0.5, JETPACK);
        }
        bonusType = Random::getInstance().randomWeighted(bonuses);
    }
}

WorldGenerator::WorldGenerator(): heightDifference(maxHeight-minHeight) {

}
