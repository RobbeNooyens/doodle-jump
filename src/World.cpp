//
// Created by robbe on 20/11/2021.
//

#include "World.h"
#include "factories/AbstractFactory.h"
#include "factories/ConcreteFactory.h"
#include "controllers/EntityController.h"
#include "controllers/PlatformController.h"
#include "SFML/Graphics.hpp"
#include "utils/Random.h"
#include "Settings.h"
#include "events/Event.h"
#include "events/EventManager.h"
#include "ScoreManager.h"

#define RENDER_BBOX(yesno) if(!yesno) return;

void World::handle(std::shared_ptr<Event> &event) {

}

World::World(): worldGenerator(std::make_unique<WorldGenerator>()) {
}

void World::update(double elapsed) {
    player->update(elapsed);
    for(auto& platform: platforms) {
        platform->update(elapsed);
    }
    for(auto& bonus: bonuses) {
        bonus->update(elapsed);
    }
    for(auto& tile: tiles) {
        tile->update(elapsed);
    }
    // Remove destroyed objects
    platforms.erase(std::remove_if(platforms.begin(), platforms.end(), [](auto& platform){ return platform->isDestroyed(); }), platforms.end());
    for(auto& platform: platforms) {
        if(platform->isDestroyed()) {
            platform.reset();
        }
    }
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
    std::shared_ptr<controllers::TileController> tile = factory->loadTile();
    tile->moveTo(200, 0);
    tiles.push_back(tile);
    std::shared_ptr<controllers::TileController> tile2 = factory->loadTile();
    tile2->moveTo(200, 400);
    tiles.push_back(tile2);
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

void drawBoundingBox(sf::RenderWindow &window, std::shared_ptr<EntityController> entity) {
    RENDER_BBOX(false)
    CollisionBox box = entity->getCollisionBox();
    sf::RectangleShape cbox;
    cbox.setSize(sf::Vector2f(box.width(), box.height()));
    cbox.setPosition(box.upperLeft.first, box.upperLeft.second);
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

void World::createPlatform() {
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(PlatformType::STATIC);
    auto center = platform->getCollisionBox().getRelativeCenter();
    platform->moveTo(Random::getInstance().generate(center.first, settings::screenWidth-center.first), -center.second);
    platforms.push_back(platform);
}
