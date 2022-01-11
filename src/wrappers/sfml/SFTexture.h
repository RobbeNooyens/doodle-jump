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

    /**
     * @brief SFML wrapper for a texture
     */
    class SFTexture : public TextureWrapper {
    public:
        // Constructor
        /**
         * @brief Constructor
         * @param file file containing the texture
         * @param width texture width
         * @param height texture height
         * @param boundingBox texture relative bounding box
         */
        SFTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> boundingBox);

        // Getters
        /**
         * @return relative texture bounding box
         */
        const std::shared_ptr<BoundingBox> &getBoundingBox() const override;
        /**
         * @return texture width
         */
        double getWidth() const override;
        /**
         * @return texture height
         */
        double getHeight() const override;
        /**
         * @return wrapped SFML texture object
         */
        const sf::Texture &getTexture();


    private:
        const double height;
        const double width;
        const std::shared_ptr<BoundingBox> boundingBox;
        sf::Texture texture{};

    };

}


#endif //DOODLEJUMP_SFTEXTURE_H
