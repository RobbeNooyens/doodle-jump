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

#ifndef DOODLEJUMP_SPRITEWRAPPER_H
#define DOODLEJUMP_SPRITEWRAPPER_H

#include <string>

namespace wrappers {
    class TextureWrapper;
}

namespace wrappers {

    /**
     * @brief Wrapper for a sprite object
     */
    class SpriteWrapper {
    public:
        /**
         * @brief Sets the sprite's texture
         * @param texture texture to apply to the sprite
         */
        virtual void setTexture(std::shared_ptr<TextureWrapper> &texture) = 0;

        /**
         * @param x new x coordinate
         * @param y new y coordinate
         */
        virtual void setPosition(float x, float y) = 0;

        /**
         * @param factorX width scaling factor
         * @param factorY height scaling factor
         */
        virtual void setScale(float factorX, float factorY) = 0;
    };

}

#endif //DOODLEJUMP_SPRITEWRAPPER_H
