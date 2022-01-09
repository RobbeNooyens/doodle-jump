//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SPRITEWRAPPER_H
#define DOODLEJUMP_SPRITEWRAPPER_H

#include <string>

namespace wrappers {
    class TextureWrapper;
}

namespace wrappers {

    class SpriteWrapper {
    public:
        virtual void setTexture(std::shared_ptr<TextureWrapper> &texture) = 0;

        virtual void setPosition(float x, float y) = 0;

        virtual void setScale(float factorX, float factorY) = 0;
    };

}

#endif //DOODLEJUMP_SPRITEWRAPPER_H
