//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_WRAPPERFACTORY_H
#define DOODLEJUMP_WRAPPERFACTORY_H

#include <memory>
#include "EventWrapper.h"

class SpriteWrapper;
class TextureWrapper;
class WindowWrapper;
class TextWrapper;
class BoundingBox;

class WrapperFactory {
public:
    virtual std::shared_ptr<SpriteWrapper> createSprite() = 0;
    virtual std::shared_ptr<TextureWrapper> createTexture(const std::string& file, double width, double height, std::shared_ptr<BoundingBox>& bbox) = 0;
    virtual std::shared_ptr<WindowWrapper> createWindow(const std::string& applicationName, unsigned int width, unsigned int height) = 0;
    virtual std::shared_ptr<TextWrapper> createText(std::string& content, int size = 12) = 0;
    virtual std::shared_ptr<EventWrapper> createEvent() = 0;
};

#endif //DOODLEJUMP_WRAPPERFACTORY_H
