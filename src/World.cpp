//
// Created by robbe on 20/11/2021.
//

#include "World.h"
#include "factories/AbstractFactory.h"
#include "factories/ConcreteFactory.h"
#include "controllers/EntityController.h"
#include "controllers/PlatformController.h"
#include "SFML/Graphics.hpp"
#include "events/Event.h"
#include "events/EventManager.h"
#include "ScoreManager.h"
#include "bounding_box/BoundingBox.h"
#include "Settings.h"
#include "events/PlayerUsesBonusEvent.h"
#include "events/PlayerBouncesOnPlatformEvent.h"

#define RENDER_BBOX(yesno) if(!yesno) return;

void World::handle(std::shared_ptr<Event> &event) {

}

World::World(): worldGenerator(std::make_unique<WorldGenerator>()) {
}

void World::update(double elapsed) {
    player->update(elapsed);
    for(auto& platform: platforms)
        platform->update(elapsed);
    for(auto& bonus: bonuses)
        bonus->update(elapsed);
    for(auto& tile: tiles)
        tile->update(elapsed);

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


    // Update worldgenerator
    worldGenerator->update();
}

void World::clear() {
    player.reset();
    for(auto& platform: platforms) {
        platform.reset();
    }
    platforms.clear();
}

void World::setup() {
//    std::shared_ptr<EventHandler> worldGenEventHandler = std::static_pointer_cast<EventHandler>(worldGenerator);
//    EventManager::getInstance().registerHandler(worldGenEventHandler);

    // Create Player
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
    player = factory->loadPlayer();
    player->moveTo(60, 250);

    // Create Platforms
    std::shared_ptr<controllers::PlatformController> platformStatic = factory->loadPlatform(PlatformType::STATIC);
    platformStatic->moveTo(60, 300);
    platforms.push_back(platformStatic);
    std::shared_ptr<controllers::PlatformController> platformTemporary = factory->loadPlatform(PlatformType::TEMPORARY);
    platformTemporary->moveTo(160, 200);
    platforms.push_back(platformTemporary);
    std::shared_ptr<controllers::PlatformController> platformHorizontal = factory->loadPlatform(PlatformType::HORIZONTAL);
    platformHorizontal->moveTo(260, 100);
    platforms.push_back(platformHorizontal);
    std::shared_ptr<controllers::PlatformController> platformVertical = factory->loadPlatform(PlatformType::VERTICAL);
    platformVertical->moveTo(360, 300);
    platforms.push_back(platformVertical);

    // Create Bonuses
    std::shared_ptr<controllers::BonusController> spring = factory->loadBonus(BonusType::SPRING);
    spring->moveTo(160, 500);
    bonuses.push_back(spring);
    std::shared_ptr<controllers::BonusController> jetpack = factory->loadBonus(BonusType::JETPACK);
    jetpack->moveTo(260, 500);
    bonuses.push_back(jetpack);

    // Create Tiles
    double tileBottom = 0;
    while(tileBottom < settings::screenHeight) {
        std::shared_ptr<controllers::TileController> tile = factory->loadTile();
        tile->moveTo(tile->getBoundingBox()->getWidth()/2,tileBottom - tile->getBoundingBox()->getHeight()/2);
        tiles.push_back(tile);
        tileBottom += tile->getBoundingBox()->getHeight();
    }
    std::shared_ptr<controllers::TileController> tile = factory->loadTile();
    tile->moveTo(tile->getBoundingBox()->getWidth()/2,tileBottom - tile->getBoundingBox()->getHeight()/2);
    tiles.push_back(tile);
}

World &World::getInstance() {
    static World INSTANCE;
    return INSTANCE;
}

std::shared_ptr<controllers::PlayerController> &World::getPlayer() {
    return player;
}

std::vector<std::shared_ptr<controllers::PlatformController>> World::getPlatforms() {
    return platforms;
}

std::vector<std::shared_ptr<controllers::BonusController>> &World::getBonuses() {
    return bonuses;
}

void drawBoundingBox(sf::RenderWindow &window, const std::shared_ptr<EntityController>& entity) {
    RENDER_BBOX(false)
    auto box = entity->getBoundingBox();
    sf::RectangleShape cbox;
    cbox.setSize(sf::Vector2f(box->getWidth(), box->getHeight()));
    cbox.setPosition(box->getLeft(), box->getTop());
    cbox.setOutlineColor(sf::Color::Red);
    cbox.setOutlineThickness(1);
    cbox.setFillColor(sf::Color::Transparent);
    window.draw(cbox);
}

void World::redraw(sf::RenderWindow &window) {
    for(auto& tile: tiles) {
        window.draw(tile->getSprite());
        drawBoundingBox(window, tile);
    }
    for(auto& bonus: bonuses) {
        window.draw(bonus->getSprite());
        drawBoundingBox(window, bonus);
    }
    for(auto& platform: platforms) {
        window.draw(platform->getSprite());
        drawBoundingBox(window, platform);
    }
    drawBoundingBox(window, player);
    window.draw(player->getSprite());
    window.draw(ScoreManager::getInstance().getText());
}

void World::addPlatform(std::shared_ptr<controllers::PlatformController> &platform) {
    platforms.push_back(platform);
}

void World::addBonus(std::shared_ptr<controllers::BonusController> &bonus) {
    bonuses.push_back(bonus);
}

void World::checkCollisions(double previousPlayerBottom) {
    auto playerBox = player->getBoundingBox();
    // Check bonuses
    for(auto& bonus: bonuses) {
        auto bonusBox = bonus->getBoundingBox();
        if(bonusBox->collides(playerBox)) {
            if(previousPlayerBottom >= bonusBox->getBottom())
                continue;
            if(playerBox->getBottom() < bonusBox->getTop())
                continue;
            std::shared_ptr<Event> bonusEvent = std::make_shared<PlayerUsesBonusEvent>(bonus->getType(), bonusBox->getTop(), bonus->getId());
            EventManager::getInstance().invoke(bonusEvent);
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
            std::shared_ptr<Event> platformEvent = std::make_shared<PlayerBouncesOnPlatformEvent>(platformBox->getTop(), platform->getId());
            EventManager::getInstance().invoke(platformEvent);
        }
    }
}
