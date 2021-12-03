//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERVIEW_H
#define DOODLEJUMP_PLAYERVIEW_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "EntityView.h"

enum PlayerOrientation { ORIENTATION_LEFT, ORIENTATION_RIGHT };

namespace views {
    class PlayerView: public EntityView {
    public:
        PlayerView();

        void lookRight();
        void lookLeft();

    private:
        PlayerOrientation orientation = ORIENTATION_LEFT;

    };
}


#endif //DOODLEJUMP_PLAYERVIEW_H
