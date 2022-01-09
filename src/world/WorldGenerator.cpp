//
// Created by robnoo on 4/12/21.
//

#include "WorldGenerator.h"

#include <utility>
#include <iostream>
#include "../events/HeightChangedEvent.h"
#include "World.h"
#include "../utils/Random.h"
#include "../factories/ConcreteEntityFactory.h"
#include "../Settings.h"
#include "../bounding_box/BoundingBox.h"
#include "Camera.h"

void WorldGenerator::update() {
    auto worldPtr = world.lock();
    while(worldPtr->camera->getHeight() >= nextHeight) {
        generatePlatform();
        calculateNextPlatformHeight();
    }
}

void WorldGenerator::generatePlatform() {
    auto worldPtr = world.lock();
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(nextPlatformType);
    auto midX = platform->getBoundingBox()->getWidth()/2;
    auto midY = platform->getBoundingBox()->getHeight()/2;
    auto platformX = Random::getInstance().generate<double>(midX, settings::screenWidth-midX);
    auto platformY = -midY+(worldPtr->camera->getHeight()-nextHeight);
    platform->setPosition(platformX, platformY);
    worldPtr->platforms.push_back(platform);
    if(addBonus) {
        std::shared_ptr<controllers::BonusController> bonusController = factory->loadBonus(bonusType);
        bonusController->setPlatform(platform);
        platform->setBonus(bonusController);
        worldPtr->bonuses.push_back(bonusController);
    }
}

void WorldGenerator::calculateNextPlatformHeight() {
    auto worldPtr = world.lock();
    double height = worldPtr->camera->getHeight();
    double difficulty = std::min(height / 40000.0, 1.0);
    double intervalBegin = difficulty/2;
    double intervalEnd = difficulty + 0.5;
    int yRelative = (int) (Random::getInstance().generate(intervalBegin, intervalEnd) * heightDifference);
    previousHeight = nextHeight;
    nextHeight = previousHeight + (settings::minPlatformDifference + yRelative);
    std::map<PlatformType, double> platformRarityMap;
    for(auto& entry: settings::platformRarityMap)
        platformRarityMap.emplace(entry.first, std::max(entry.second.first*height+entry.second.second, 0.0));
    nextPlatformType = Random::getInstance().randomWeighted(platformRarityMap);
    // Decide whether or not to include a bonus
    addBonus = Random::getInstance().generate<double>() <= settings::bonusSpawnRate;
    if(addBonus && height > 500 && nextPlatformType != TEMPORARY) {
        bonusType = Random::getInstance().randomWeighted(settings::bonusRarityMap);
    }
}

WorldGenerator::WorldGenerator(std::shared_ptr<World> world, std::shared_ptr<EntityFactory>& factory):
    nextHeight(-((double)settings::screenHeight)), // prevent empty startscreen
    world(world),
    factory(factory),
    heightDifference(settings::maxPlatformDifference-settings::minPlatformDifference) {
    setup();
}

void WorldGenerator::reset() {
    this->nextHeight = 0;
    this->nextPlatformType = STATIC;
    this->addBonus = false;
    this->previousHeight = 0;
}

void WorldGenerator::setup() {
    auto worldPtr = world.lock();

    // Create player
    worldPtr->player = factory->loadPlayer();
    double playerHeight = worldPtr->player->getBoundingBox()->getHeight();
    worldPtr->player->setPosition(settings::screenWidth/2.0, settings::screenHeight-playerHeight);

    // Create score
    worldPtr->score = factory->loadText(std::to_string(0), 40);
    worldPtr->score->setPosition(20, 10);

    // Create Tiles
    double tileBottom = 0;
    while(tileBottom < settings::screenHeight) {
        std::shared_ptr<controllers::TileController> tile = factory->loadTile();
        tile->setPosition(tile->getBoundingBox()->getWidth() / 2, tileBottom - tile->getBoundingBox()->getHeight() / 2);
        worldPtr->tiles.push_back(tile);
        tileBottom += tile->getBoundingBox()->getHeight();
    }
    std::shared_ptr<controllers::TileController> tile = factory->loadTile();
    tile->setPosition(tile->getBoundingBox()->getWidth() / 2, tileBottom - tile->getBoundingBox()->getHeight() / 2);
    worldPtr->tiles.push_back(tile);
}

WorldGenerator::~WorldGenerator() {
    factory.reset();
    world.reset();
}
