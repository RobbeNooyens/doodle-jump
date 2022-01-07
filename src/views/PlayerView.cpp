//
// Created by robnoo on 25/11/21.
//

#include "PlayerView.h"
#include "../utils/TextureLoader.h"

void views::PlayerView::lookRight() {
    if(orientation == PlayerOrientation::ORIENTATION_LEFT) {
        auto control = this->controller.lock();
        auto resource = TextureLoader::getInstance().getTexture(entity, textureRight);
        control->load(resource);
        orientation = PlayerOrientation::ORIENTATION_RIGHT;
    }
}

void views::PlayerView::lookLeft() {
    if(orientation == PlayerOrientation::ORIENTATION_RIGHT) {
        auto control = this->controller.lock();
        auto resource = TextureLoader::getInstance().getTexture(entity, textureLeft);
        control->load(resource);
        orientation = PlayerOrientation::ORIENTATION_LEFT;
    }
}

views::PlayerView::PlayerView(std::shared_ptr<EntityController> controller) : EntityView(controller) {

}
