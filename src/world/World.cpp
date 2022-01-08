//
// Created by robbe on 20/11/2021.
//

#include "World.h"
#include "../events/Event.h"
#include "../events/EventManager.h"
#include "../bounding_box/BoundingBox.h"
#include "../events/PlayerUsesBonusEvent.h"
#include "../events/PlayerBouncesOnPlatformEvent.h"
#include "../wrappers/WindowWrapper.h"
#include "../wrappers/TextWrapper.h"
#include "WorldGenerator.h"
#include "../ScoreManager.h"

void World::update(double elapsed) {
    double previousBottom = player->getBoundingBox()->getBottom();
    player->update(elapsed);
    for(auto& platform: platforms)
        platform->update(elapsed);
    for(auto& bonus: bonuses)
        bonus->update(elapsed);
    for(auto& tile: tiles)
        tile->update(elapsed);
    checkCollisions(previousBottom);

    // Remove destroyed objects
    for(auto& platform: platforms) {
        if(platform->isDestroyed()) {
            platform->unregister();
            platform.reset();
        }
    }
    platforms.erase(std::remove_if(platforms.begin(), platforms.end(), [](auto& platform){ return !platform; }), platforms.end());
    for(auto& bonus: bonuses) {
        if(bonus->isDestroyed()) {
            bonus->unregister();
            bonus.reset();
        }
    }
    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(), [](std::shared_ptr<controllers::BonusController>& bonus){ return !bonus; }), bonuses.end());
    for(auto& tile: tiles) {
        if(tile->isDestroyed()) {
            tile->recycle();
        }
    }
    score->update(std::to_string((int) ScoreManager::getInstance().getScore()));
}

void World::draw(std::shared_ptr<WindowWrapper>& window) {
    for(auto& tile: tiles)
        tile->draw(window);
    for (auto &bonus: bonuses)
        bonus->draw(window);
    for (auto &platform: platforms)
        platform->draw(window);
    player->draw(window);
    score->draw(window);
}

void World::checkCollisions(double previousPlayerBottom) {
    auto playerBox = player->getBoundingBox();
    // Check bonuses
    for(auto& bonus: bonuses) {
        auto bonusBox = bonus->getBoundingBox();
        if(bonusBox->collides(playerBox)) {
            if(previousPlayerBottom >= bonusBox->getTop())
                continue;
            if(playerBox->getBottom() < bonusBox->getTop())
                continue;
            EventManager::getInstance().invoke(std::make_shared<PlayerUsesBonusEvent>(bonus->getType(), bonusBox->getTop(), bonus->getId()));
        }
    }
    // Check platforms
    for(auto& platform: platforms) {
        auto platformBox = platform->getBoundingBox();
        if(platformBox->collides(playerBox)) {
            if(previousPlayerBottom >= platformBox->getTop())
                continue;
            if(playerBox->getBottom() < platformBox->getTop())
                continue;
            EventManager::getInstance().invoke(std::make_shared<PlayerBouncesOnPlatformEvent>(platformBox->getTop(), platform->getId()));
        }
    }
}

World::~World() {
    player->unregister();
    player.reset();
    for(auto& platform: platforms) {
        platform->unregister();
        platform.reset();
    }
    platforms.clear();
    for(auto& bonus: bonuses){
        bonus->unregister();
        bonus.reset();
    }
    bonuses.clear();
    score.reset();
    for(auto& tile: tiles) {
        tile->unregister();
        tile.reset();
    }
}
