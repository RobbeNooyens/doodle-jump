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
#include "SFSprite.h"
#include "SFTexture.h"
#include "SFWindow.h"
#include "SFText.h"
#include "SFEvent.h"

std::shared_ptr<wrappers::SpriteWrapper> wrappers::sfml::SFWrapperFactory::createSprite() {
    return std::make_shared<SFSprite>();
}

std::shared_ptr<wrappers::WindowWrapper>
wrappers::sfml::SFWrapperFactory::createWindow(const std::string &applicationName, unsigned int width, unsigned int height) {
    return std::make_shared<SFWindow>(applicationName, width, height);
}

std::shared_ptr<wrappers::TextWrapper> wrappers::sfml::SFWrapperFactory::createText(std::string& content, unsigned int size) {
    return std::make_shared<SFText>(content, size);
}

std::shared_ptr<wrappers::TextureWrapper>
wrappers::sfml::SFWrapperFactory::createTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) {
    return std::make_shared<SFTexture>(file, width, height, bbox);
}

std::shared_ptr<wrappers::EventWrapper> wrappers::sfml::SFWrapperFactory::createEvent() {
    return std::make_shared<SFEvent>();
}
