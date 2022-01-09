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

    class SFSprite : public SpriteWrapper {
    public:
        sf::Sprite &getSprite();

        void setPosition(float x, float y) override;

        void setScale(float factorX, float factorY) override;

        void setTexture(std::shared_ptr<TextureWrapper> &texture) override;

    private:
        sf::Sprite sprite{};
    };

}
#endif //DOODLEJUMP_SFSPRITE_H
