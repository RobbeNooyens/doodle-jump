//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERVIEW_H
#define DOODLEJUMP_PLAYERVIEW_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "EntityView.h"
#include "../enums/Direction.h"

namespace views {
    class PlayerView: public EntityView {
    public:
        PlayerView();

        void updateDirections(Direction horizontal, Direction vertical);

    private:
        Direction horizontalDirection = LEFT;
        Direction verticalDirection = UP;

    };
}


#endif //DOODLEJUMP_PLAYERVIEW_H
