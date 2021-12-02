//
// Created by robnoo on 25/11/21.
//

#include "PlatformController.h"
#include "../utils/ResourceLoader.h"

void controllers::PlatformController::handle(std::shared_ptr<Event> &event) {
}

void controllers::PlatformController::update(double elapsed) {

}

controllers::PlatformController::PlatformController() {
    view = std::make_shared<views::PlatformView>();
}

controllers::StaticPlatformController::StaticPlatformController(): PlatformController() {
    model = std::make_shared<models::StaticPlatform>();
}

void controllers::StaticPlatformController::update(double elapsed) {

}
