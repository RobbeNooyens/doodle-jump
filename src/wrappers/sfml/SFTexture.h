//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFTEXTURE_H
#define DOODLEJUMP_SFTEXTURE_H


#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include "../TextureWrapper.h"

class SFTexture: public TextureWrapper {
public:
    // Constructor
    SFTexture(double width, double height, std::shared_ptr<BoundingBox> boundingBox);

    // Loader
    void loadFromFile(const std::string &file) override;

    // Getters
    const std::shared_ptr<BoundingBox> &getBoundingBox() const override;
    double getWidth() const override;
    double getHeight() const override;
    const sf::Texture& getTexture();


private:
    const double height;
    const double width;
    const std::shared_ptr<BoundingBox> boundingBox;
    sf::Texture texture;

};


#endif //DOODLEJUMP_SFTEXTURE_H
