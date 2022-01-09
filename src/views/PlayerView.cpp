/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "PlayerView.h"

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
