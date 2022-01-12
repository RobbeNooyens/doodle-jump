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

#include "SFWrapperFactory.h"

std::shared_ptr<wrappers::SpriteWrapper> wrappers::sfml::SFWrapperFactory::createSprite() {
    return nullptr;
}

std::shared_ptr<wrappers::WindowWrapper>
wrappers::sfml::SFWrapperFactory::createWindow(const std::string &applicationName, unsigned int width, unsigned int height) {
    return nullptr;
}

std::shared_ptr<wrappers::TextWrapper> wrappers::sfml::SFWrapperFactory::createText(std::string& content, unsigned int size) {
    return nullptr;
}

std::shared_ptr<wrappers::TextureWrapper>
wrappers::sfml::SFWrapperFactory::createTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) {
    return nullptr;
}

std::shared_ptr<wrappers::EventWrapper> wrappers::sfml::SFWrapperFactory::createEvent() {
    return nullptr;
}