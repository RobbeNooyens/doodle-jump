//
// Created by robnoo on 25/11/21.
//

#include "PlayerView.h"
#include "../utils/ResourceLoader.h"

views::PlayerView::PlayerView(): EntityView() {}

void views::PlayerView::lookRight() {
    if(orientation == PlayerOrientation::ORIENTATION_LEFT) {
        auto control = this->controller.lock();
        auto resource = ResourceLoader::getInstance().getResource(entity, textureRight);
        control->load(resource);
        orientation = PlayerOrientation::ORIENTATION_RIGHT;
    }
}

void views::PlayerView::lookLeft() {
    if(orientation == PlayerOrientation::ORIENTATION_RIGHT) {
        auto control = this->controller.lock();
        auto resource = ResourceLoader::getInstance().getResource(entity, textureLeft);
        control->load(resource);
        orientation = PlayerOrientation::ORIENTATION_LEFT;
    }
}
