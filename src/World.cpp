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

void drawBoudingBox(sf::RenderWindow &window, std::shared_ptr<EntityController> entity) {
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
    drawBoudingBox(window, player);
    window.draw(player->getSprite());
    sf::CircleShape position;
    position.setRadius(2);
    position.setFillColor(sf::Color::Yellow);
    position.setPosition(player->getX(), player->getY());
    window.draw(position);
    for(auto& platform: platforms) {
        window.draw(platform->getSprite());
        drawBoudingBox(window, platform);
    }

}
