//
// Created by robnoo on 6/01/22.
//

#include "SFTexture.h"

#include <utility>

SFTexture::SFTexture(const double width, const double height, std::shared_ptr<BoundingBox> boundingBox): width(width), height(height), boundingBox(std::move(boundingBox)) {}

void SFTexture::loadFromFile(const std::string &file) {
    // TODO: error handling
    texture.loadFromFile(file);
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
