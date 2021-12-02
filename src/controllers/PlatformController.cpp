//
// Created by robnoo on 25/11/21.
//

#include "PlatformController.h"
#include "../utils/ResourceLoader.h"

void controllers::PlatformController::handle(std::shared_ptr<Event> &event) {
}

void controllers::PlatformController::update(double elapsed) {

}

controllers::PlatformController::PlatformController() = default;

void controllers::StaticPlatformController::load(double size) {
    std::string texture_id = "static";
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entityType, texture_id);
    this->model = std::make_shared<models::StaticPlatform>();
    model->setSize(size);
    model->setBoundingBox(resource->boundingBox);
    this->view = std::make_shared<views::PlatformView>();
    view->setTexture(resource->texture);
    view->setWidth(resource->width);
    view->setHeight(resource->height);
    view->setSize(size);
}
