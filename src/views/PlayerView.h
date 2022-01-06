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
        explicit PlayerView(std::shared_ptr<EntityController>& controller);

        void lookRight();
        void lookLeft();

    private:
        std::string entity = "player";
        std::string textureLeft = "left";
        std::string textureRight = "right";
        PlayerOrientation orientation = ORIENTATION_LEFT;

    };
}


#endif //DOODLEJUMP_PLAYERVIEW_H
