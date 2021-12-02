//
// Created by robbe on 20/11/2021.
//

#include "World.h"
#include "factories/AbstractFactory.h"
#include "factories/ConcreteFactory.h"
#include "SFML/Graphics.hpp"

void World::handle(std::shared_ptr<Event> &event) {

}

World::World() {

}

void World::update(double elapsed) {
    player->update(elapsed);
    for(auto& platform: platforms) {
        platform->update(elapsed);
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
    std::shared_ptr<AbstractFactory> factory = std::make_shared<ConcreteFactory>();
    player = factory->loadPlayer();
    std::shared_ptr<controllers::PlatformController> platformController = factory->loadPlatform(PlatformType::STATIC);
    platformController->moveTo(60, 300);
    platforms.push_back(platformController);
}

World &World::getInstance() {
    static World INSTANCE;
    return INSTANCE;
}

std::shared_ptr<controllers::PlayerController> &World::getPlayer() {
    return player;
}

std::vector<std::shared_ptr<controllers::PlatformController>> &World::getPlatforms() {
    return platforms;
}

std::vector<std::shared_ptr<controllers::BonusController>> &World::getBonuses() {
    return bonuses;
}

void World::redraw(sf::RenderWindow &window) {
    window.draw(player->getSprite());
    for(auto& platform: platforms)
        window.draw(platform->getSprite());

}
