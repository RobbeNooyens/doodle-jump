//
// Created by robnoo on 4/12/21.
//

#include "WorldGenerator.h"

#include <utility>
#include "../events/ReachedNewHeightEvent.h"
#include "World.h"
#include "../utils/Random.h"
#include "../factories/ConcreteEntityFactory.h"
#include "../Settings.h"
#include "../bounding_box/BoundingBox.h"
#include "../Camera.h"

void WorldGenerator::update() {
    while(Camera::getInstance().getHeight() >= nextHeight) {
        generatePlatform();
        calculateNextPlatformHeight();
    }
}

void WorldGenerator::generatePlatform() {
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(nextPlatformType);
    auto midX = platform->getBoundingBox()->getWidth()/2;
    auto midY = platform->getBoundingBox()->getHeight()/2;
    auto platformX = Random::getInstance().generate<double>(midX, settings::screenWidth-midX);
    auto platformY = -midY+(Camera::getInstance().getHeight()-nextHeight);
    platform->setPosition(platformX, platformY);
    world->platforms.push_back(platform);
    if(addBonus) {
        std::shared_ptr<controllers::BonusController> bonusController = factory->loadBonus(bonusType);
        bonusController->setPlatform(platform);
        world->bonuses.push_back(bonusController);
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

WorldGenerator::WorldGenerator(std::shared_ptr<World> world, std::shared_ptr<EntityFactory>& factory):
    world(std::move(world)),
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
    // TODO move
    world->player = factory->loadPlayer();

    // Create Tiles
    double tileBottom = 0;
    while(tileBottom < settings::screenHeight) {
        std::shared_ptr<controllers::TileController> tile = factory->loadTile();
        tile->setPosition(tile->getBoundingBox()->getWidth() / 2, tileBottom - tile->getBoundingBox()->getHeight() / 2);
        world->tiles.push_back(tile);
        tileBottom += tile->getBoundingBox()->getHeight();
    }
    std::shared_ptr<controllers::TileController> tile = factory->loadTile();
    tile->setPosition(tile->getBoundingBox()->getWidth() / 2, tileBottom - tile->getBoundingBox()->getHeight() / 2);
    world->tiles.push_back(tile);
}
