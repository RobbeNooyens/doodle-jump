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
    std::shared_ptr<controllers::PlatformController> platform = factory->loadPlatform(PlatformType::STATIC);
    platform->moveTo(60, 300);
    player->moveTo(60, 100);
    platforms.push_back(platform);
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
    CollisionBox box = player->getCollisionBox();
    sf::RectangleShape cbox;
    cbox.setSize(sf::Vector2f(box.width(), box.height()));
    cbox.setPosition(player->getSprite().getPosition());
    cbox.setOutlineColor(sf::Color::Red);
    cbox.setOutlineThickness(4);
    cbox.setFillColor(sf::Color::Transparent);
    window.draw(cbox);
    window.draw(player->getSprite());
    for(auto& platform: platforms)
        window.draw(platform->getSprite());

}
