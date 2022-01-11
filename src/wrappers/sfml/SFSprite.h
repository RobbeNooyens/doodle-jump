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

#ifndef DOODLEJUMP_SFSPRITE_H
#define DOODLEJUMP_SFSPRITE_H


#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <map>
#include "../SpriteWrapper.h"

namespace wrappers::sfml {

    /**
     * @brief SFML wrapper for a sprite
     */
    class SFSprite : public SpriteWrapper {
    public:
        /**
         * @return wrapped SFML sprite
         */
        sf::Sprite &getSprite();
        /**
         * @param x new x coordinate
         * @param y new y coordinate
         */
        void setPosition(float x, float y) override;
        /**
         * @param factorX horizontal scale factor
         * @param factorY vertical scale factor
         */
        void setScale(float factorX, float factorY) override;
        /**
         * @param texture texture to use for this sprite
         */
        void setTexture(std::shared_ptr<TextureWrapper> &texture) override;

    private:
        sf::Sprite sprite{};
    };

}
#endif //DOODLEJUMP_SFSPRITE_H
