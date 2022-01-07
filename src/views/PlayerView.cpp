//
// Created by robnoo on 25/11/21.
//

#include "PlayerView.h"
#include "../utils/TextureLoader.h"

void views::PlayerView::lookRight() {
    if(orientation == PlayerOrientation::ORIENTATION_LEFT) {
        orientation = PlayerOrientation::ORIENTATION_RIGHT;
    }
}

void views::PlayerView::lookLeft() {
    if(orientation == PlayerOrientation::ORIENTATION_RIGHT) {
        orientation = PlayerOrientation::ORIENTATION_LEFT;
    }
}

views::PlayerView::PlayerView() : EntityView("player") {}
