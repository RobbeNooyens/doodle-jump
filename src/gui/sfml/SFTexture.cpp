//
// Created by robnoo on 6/01/22.
//

#include "SFTexture.h"

#include <utility>

SFTexture::SFTexture(const double width, const double height, std::shared_ptr<BoundingBox> boundingBox): width(width), height(height), boundingBox(std::move(boundingBox)) {

}

void SFTexture::loadFromFile(std::string &file) {

}

const std::shared_ptr<BoundingBox> &SFTexture::getBoundingBox() {
    return boundingBox;
}

double SFTexture::getWidth() {
    return width;
}

double SFTexture::getHeight() {
    return height;
}

const sf::Texture &SFTexture::getTexture() {
    return texture;
}
