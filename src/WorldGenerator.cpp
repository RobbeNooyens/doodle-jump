//
// Created by robnoo on 4/12/21.
//

#include <iostream>
#include "WorldGenerator.h"
#include "events/ReachedNewHeightEvent.h"
#include "World.h"
#include "utils/Random.h"
#include "factories/ConcreteFactory.h"
#include "Settings.h"
#include "bounding_box/BoundingBox.h"
#include "Camera.h"

void WorldGenerator::update() {
    while(Camera::getInstance().getHeight() >= nextHeight) {
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
    auto platformY = -midY+(Camera::getInstance().getHeight()-nextHeight);
    platform->moveTo(platformX, platformY);
    World::getInstance().addPlatform(platform);
    if(addBonus) {
        std::shared_ptr<controllers::BonusController> bonusController = factory->loadBonus(bonusType);
        bonusController->setPlatform(platform);
        World::getInstance().addBonus(bonusController);
    }
}

void WorldGenerator::calculateNextPlatformHeight() {
    double height = Camera::getInstance().getHeight();
    double difficulty = std::min(height / 40000.0, 1.0);
    double intervalBegin = difficulty/2;
    double intervalEnd = difficulty + 0.5;
    int yRelative = (int) (Random::getInstance().generate(intervalBegin, intervalEnd) * heightDifference);
    previousHeight = nextHeight;
    nextHeight = previousHeight + (settings::minPlatformDifference + yRelative);
    nextPlatformType = Random::getInstance().randomWeighted(settings::platformRarityMap);
    // Decide whether or not to include a bonus
    addBonus = Random::getInstance().generate<double>() <= settings::bonusSpawnRate;
    if(addBonus && height > 500 && nextPlatformType != TEMPORARY) {
        bonusType = Random::getInstance().randomWeighted(settings::bonusRarityMap);
    }
}

WorldGenerator::WorldGenerator(): heightDifference(settings::maxPlatformDifference-settings::minPlatformDifference) {

}
