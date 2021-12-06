//
// Created by robnoo on 4/12/21.
//

#include "WorldGenerator.h"
#include "events/ReachedNewHeightEvent.h"
#include "World.h"
#include "ScoreManager.h"
#include "utils/Random.h"
#include "factories/ConcreteFactory.h"
#include "Settings.h"

void WorldGenerator::update() {
    while(ScoreManager::getInstance().getScore() >= nextHeight) {
        generatePlatform(PlatformType::STATIC);
        calculateNextPlatformHeight();
    }
}

void WorldGenerator::generatePlatform(PlatformType type) {
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(nextPlatformType);
    auto center = platform->getCollisionBox().getRelativeCenter();
    platform->moveTo(Random::getInstance().generate<double>(center.first, settings::screenWidth-center.first), -center.second+(ScoreManager::getInstance().getScore()-nextHeight));
    World::getInstance().addPlatform(platform);
}

void WorldGenerator::generateBonusPlatform(PlatformType type, BonusType) {

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
}

WorldGenerator::WorldGenerator(): heightDifference(maxHeight-minHeight) {

}
