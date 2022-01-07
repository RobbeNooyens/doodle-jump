//
// Created by robnoo on 6/01/22.
//

#include "SFTexture.h"

#include <utility>
#include <stdexcept>

SFTexture::SFTexture(const std::string& file, const double width, const double height, std::shared_ptr<BoundingBox> boundingBox): width(width), height(height), boundingBox(std::move(boundingBox)) {
    if(!texture.loadFromFile(file)){
        // TODO: error handling
        throw std::runtime_error("Couldn't load texture");
    }
}

const std::shared_ptr<BoundingBox> &SFTexture::getBoundingBox() const {
    return boundingBox;
}

double SFTexture::getWidth() const {
    return width;
}

double SFTexture::getHeight() const {
    return height;
}

const sf::Texture &SFTexture::getTexture() {
    return texture;
}
