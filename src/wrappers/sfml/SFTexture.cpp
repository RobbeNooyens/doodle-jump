//
// Created by robnoo on 6/01/22.
//

#include "SFTexture.h"
#include "../../exceptions/TextureLoadException.h"

#include <utility>
#include <stdexcept>

wrappers::sfml::SFTexture::SFTexture(const std::string& file, const double width, const double height, std::shared_ptr<BoundingBox> boundingBox): width(width), height(height), boundingBox(std::move(boundingBox)) {
    if(!texture.loadFromFile(file)){
        throw exceptions::TextureLoadException(file);
    }
}

const std::shared_ptr<BoundingBox> &wrappers::sfml::SFTexture::getBoundingBox() const {
    return boundingBox;
}

double wrappers::sfml::SFTexture::getWidth() const {
    return width;
}

double wrappers::sfml::SFTexture::getHeight() const {
    return height;
}

const sf::Texture &wrappers::sfml::SFTexture::getTexture() {
    return texture;
}
