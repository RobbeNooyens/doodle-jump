//
// Created by robbe on 20/11/2021.
//

#include "World.h"
#include "../events/Event.h"
#include "../events/EventManager.h"
#include "../ScoreManager.h"
#include "../bounding_box/BoundingBox.h"
#include "../events/PlayerUsesBonusEvent.h"
#include "../events/PlayerBouncesOnPlatformEvent.h"
#include "../wrappers/WindowWrapper.h"
#include "../wrappers/TextWrapper.h"
#include "WorldGenerator.h"

#define RENDER_BBOX(yesno) if(!yesno) return;

World::World(std::shared_ptr<EntityFactory>& factory) {}

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
            platform.reset();
        }
    }
    platforms.erase(std::remove_if(platforms.begin(), platforms.end(), [](auto& platform){ return !platform; }), platforms.end());
    for(auto& bonus: bonuses) {
        if(bonus->isDestroyed()) {
            bonus.reset();
        }
    }
    bonuses.erase(std::remove_if(bonuses.begin(), bonuses.end(), [](std::shared_ptr<controllers::BonusController>& bonus){ return !bonus; }), bonuses.end());
    for(auto& tile: tiles) {
        if(tile->isDestroyed()) {
            tile->recycle();
        }
    }

    // Update score
    // TODO update
//    score->setText(std::to_string((int) ScoreManager::getInstance().getScore()));
}

void World::clear() {
    player.reset();
    for(auto& platform: platforms) {
        platform.reset();
    }
    platforms.clear();
    for(auto& bonus: bonuses) {
        bonus.reset();
    }
    bonuses.clear();
}

void drawBoundingBox(std::shared_ptr<WindowWrapper> &window, const std::shared_ptr<EntityController>& entity) {
    RENDER_BBOX(false)
//    auto box = entity->getBoundingBox();
//    sf::RectangleShape cbox;
//    cbox.setSize(sf::Vector2f(box->getWidth(), box->getHeight()));
//    cbox.setPosition(box->getLeft(), box->getTop());
//    cbox.setOutlineColor(sf::Color::Red);
//    cbox.setOutlineThickness(1);
//    cbox.setFillColor(sf::Color::Transparent);
//    window.draw(cbox);
}

void World::draw(std::shared_ptr<WindowWrapper>& window) {
    for(auto& tile: tiles) {
        tile->draw(window);
    }
    for (auto &bonus: bonuses) {
        bonus->draw(window);
    }
    for (auto &platform: platforms) {
        platform->draw(window);
    }
    player->draw(window);
    window->draw(score);
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
