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
#include "enums/GameState.h"
#include "Camera.h"

#define RENDER_BBOX(yesno) if(!yesno) return;

World::World(): worldGenerator(std::make_unique<WorldGenerator>()) {}

void World::update(double elapsed) {
    if(gameState == PAUSED || gameState == MENU)
        return;
    if(player->isDestroyed()) {
        gameState = MENU;
        clear();
        ScoreManager::getInstance().menuLayout();
        ScoreManager::getInstance().writeHighScore();
        return;
    }
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
    for(auto& bonus: bonuses) {
        bonus.reset();
    }
    bonuses.clear();
}

void World::setup() {
    // Create Tiles
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
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

    if(gameState == MENU)
        ScoreManager::getInstance().menuLayout();
    else
        ScoreManager::getInstance().gameLayout();
}

World &World::getInstance() {
    static World INSTANCE;
    return INSTANCE;
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
    if(gameState == PLAYING || gameState == PAUSED) {
        for (auto &bonus: bonuses) {
            window.draw(bonus->getSprite());
            drawBoundingBox(window, bonus);
        }
        for (auto &platform: platforms) {
            window.draw(platform->getSprite());
            drawBoundingBox(window, platform);
        }
        drawBoundingBox(window, player);
        window.draw(player->getSprite());
    }
    window.draw(ScoreManager::getInstance().getScoreText());
    if(gameState == MENU)
        window.draw(ScoreManager::getInstance().getHighScoreText());
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
            if(previousPlayerBottom >= bonusBox->getTop())
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

void World::spacebarPressed() {
    if(gameState == MENU) {
        gameState = PLAYING;
        ScoreManager::getInstance().gameLayout();
        ScoreManager::getInstance().setScore(0);
        Camera::getInstance().setHeight(settings::screenHeight);
        std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
        worldGenerator->reset();
        player = factory->loadPlayer();
        player->moveTo(settings::screenWidth/2.0, settings::screenHeight + player->getBoundingBox()->getHeight());
    } else if(gameState == PLAYING) {
        gameState = PAUSED;
    } else if(gameState == PAUSED) {
        gameState = PLAYING;
    }

}
