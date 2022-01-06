//
// Created by robnoo on 6/01/22.
//

#include "SFWrapperFactory.h"
#include "SFSprite.h"
#include "SFTexture.h"
#include "SFWindow.h"
#include "SFText.h"

std::shared_ptr<SpriteWrapper> SFWrapperFactory::loadSprite() {
    return std::shared_ptr<SFSprite>();
}

std::shared_ptr<WindowWrapper>
SFWrapperFactory::loadWindow(const std::string &applicationName, unsigned int width, unsigned int height) {
    return std::shared_ptr<SFWindow>(applicationName, width, height);
}

std::shared_ptr<TextWrapper> SFWrapperFactory::loadText(std::string& content, int size) {
    return std::shared_ptr<SFText>();
}

std::shared_ptr<TextureWrapper>
SFWrapperFactory::loadTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) {
    std::shared_ptr<TextureWrapper> texture = std::shared_ptr<SFTexture>(width, height, bbox);
    return texture;
}
