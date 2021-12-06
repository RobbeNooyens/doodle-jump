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

void WorldGenerator::update() {
    while(ScoreManager::getInstance().getScore() >= nextHeight) {
        generatePlatform();
        calculateNextPlatformHeight();
    }
}

void WorldGenerator::generatePlatform() {
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(nextPlatformType);
    auto center = platform->getCollisionBox().getRelativeCenter();
    auto platformX = Random::getInstance().generate<double>(center.first, settings::screenWidth-center.first);
    auto platformY = -center.second+(ScoreManager::getInstance().getScore()-nextHeight);
    platform->moveTo(platformX, platformY);
    World::getInstance().addPlatform(platform);
    if(addBonus) {
        std::shared_ptr<controllers::BonusController> bonusController = factory->loadBonus(bonusType);
//        bonusController->attachTo(platform);
//        bonusController->syncWithPlatform();
        World::getInstance().addBonus(bonusController);
    }
}

void WorldGenerator::calculateNextPlatformHeight() {
    double score = ScoreManager::getInstance().getScore();
    double difficulty = std::min(score / 20000.0, 1.0);
    double intervalBegin = difficulty/2;
    double intervalEnd = difficulty + 0.5;
    int yRelative = (int) (Random::getInstance().generate(intervalBegin, intervalEnd) * heightDifference);
    previousHeight = nextHeight;
    nextHeight = previousHeight + (minHeight + yRelative);
    std::map<double, PlatformType> types = {{1, STATIC}};
    if(score > 1000) {
        types.emplace(0.5, HORIZONTAL);
    }
    if(score > 5000) {
        types.emplace(0.2, TEMPORARY);
    }
    if(score > 10000) {
        types.emplace(0.1, VERTICAL);
    }
    nextPlatformType = Random::getInstance().randomWeighted(types);
    // Decide whether or not to include a bonus
    addBonus = Random::getInstance().generate<double>() <= 0.5;
    std::cout << addBonus << std::endl;
    if(addBonus && score > 500) {
        std::map<double, BonusType> bonuses;
        if(score > 500) {
            bonuses.emplace(1, SPRING);
        }
        if(score > 1500) {
            bonuses.emplace(0.1, JETPACK);
        }
        bonusType = Random::getInstance().randomWeighted(bonuses);
    }
}

WorldGenerator::WorldGenerator(): heightDifference(maxHeight-minHeight) {

}
