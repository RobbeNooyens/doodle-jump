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

#ifndef DOODLEJUMP_SFTEXTURE_H
#define DOODLEJUMP_SFTEXTURE_H


#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include "../TextureWrapper.h"

namespace wrappers::sfml {

    class SFTexture : public TextureWrapper {
    public:
        // Constructor
        SFTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> boundingBox);

        // Getters
        const std::shared_ptr<BoundingBox> &getBoundingBox() const override;

        double getWidth() const override;

        double getHeight() const override;

        const sf::Texture &getTexture();


    private:
        const double height;
        const double width;
        const std::shared_ptr<BoundingBox> boundingBox;
        sf::Texture texture;

    };

}


#endif //DOODLEJUMP_SFTEXTURE_H
