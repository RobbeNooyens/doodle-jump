//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFTEXTURE_H
#define DOODLEJUMP_SFTEXTURE_H


#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include "../../bounding_box/BoundingBox.h"
#include "../TextureWrapper.h"

class SFTexture: public TextureWrapper {
public:
    // Constructor
    SFTexture(double width, double height, std::shared_ptr<BoundingBox>  boundingBox);

    // Loader
    void loadFromFile(std::string &file) override;

    // Getters
    const std::shared_ptr<BoundingBox> &getBoundingBox() override;
    double getWidth() override;
    double getHeight() override;
    const sf::Texture& getTexture();


private:
    const double height;
    const double width;
    const std::shared_ptr<BoundingBox> boundingBox;
    const sf::Texture texture;

};


#endif //DOODLEJUMP_SFTEXTURE_H
