//
// Created by robnoo on 6/01/22.
//

#include "SFWrapperFactory.h"
#include "SFSprite.h"
#include "SFTexture.h"
#include "SFWindow.h"
#include "SFText.h"
#include "SFEvent.h"

std::shared_ptr<SpriteWrapper> SFWrapperFactory::createSprite() {
    return std::make_shared<SFSprite>();
}

std::shared_ptr<WindowWrapper>
SFWrapperFactory::createWindow(const std::string &applicationName, unsigned int width, unsigned int height) {
    return std::make_shared<SFWindow>(applicationName, width, height);
}

std::shared_ptr<TextWrapper> SFWrapperFactory::createText(std::string& content, unsigned int size) {
    return std::make_shared<SFText>(content, size);
}

std::shared_ptr<TextureWrapper>
SFWrapperFactory::createTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) {
    return std::make_shared<SFTexture>(file, width, height, bbox);
}

std::shared_ptr<EventWrapper> SFWrapperFactory::createEvent() {
    return std::make_shared<SFEvent>();
}
