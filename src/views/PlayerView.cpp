//
// Created by robnoo on 25/11/21.
//

#include "PlayerView.h"
#include "../utils/TextureLoader.h"

views::PlayerView::PlayerView() : EntityView("player") {}

void views::PlayerView::updateDirections(Direction horizontal, Direction vertical) {
    if(horizontalDirection != horizontal || verticalDirection != vertical) {
        horizontalDirection = horizontal;
        verticalDirection = vertical;
        std::string textureId = verticalDirection == UP ? "jump_" : "";
        textureId.append(horizontalDirection == LEFT ? "left" : "right");
        setTexture(textureId);
    }
}
