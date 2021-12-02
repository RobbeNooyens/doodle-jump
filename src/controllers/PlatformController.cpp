//
// Created by robnoo on 25/11/21.
//

#include "PlatformController.h"
#include "../utils/ResourceLoader.h"

void controllers::PlatformController::handle(std::shared_ptr<Event> &event) {
}

sf::Sprite &controllers::PlatformController::getSprite() {
    return platformView->getSprite();
}

void controllers::PlatformController::update(double elapsed) {

}

void controllers::PlatformController::moveTo(double x, double y) {
    platformModel->moveTo(x, y);
    platformView->moveTo(x, y);
}

CollisionBox controllers::PlatformController::createCollisionBox() {
    auto box = platformModel->getBox();
    return {box.first, box.second};
}

controllers::PlatformController::PlatformController() = default;

void controllers::StaticPlatformController::load(double width) {
    this->platformModel = std::make_shared<models::StaticPlatform>();
    platformModel->setSize(width);
    this->platformView = std::make_shared<views::PlatformView>();
    std::string texture_id = "static";
    platformView->setTexture(ResourceLoader::getInstance().getTexture(entityType, texture_id));
    platformView->setSize(width);
}
