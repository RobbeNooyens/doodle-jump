//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_WRAPPERFACTORY_H
#define DOODLEJUMP_WRAPPERFACTORY_H

#include <memory>

class SpriteWrapper;
class TextureWrapper;
class WindowWrapper;
class TextWrapper;

class WrapperFactory {
public:
    virtual std::shared_ptr<SpriteWrapper> loadSprite() = 0;
    virtual std::shared_ptr<TextureWrapper> loadTexture() = 0;
    virtual std::shared_ptr<WindowWrapper> loadWindow(const std::string& applicationName, unsigned int width, unsigned int height) = 0;
    virtual std::shared_ptr<TextWrapper> loadText(std::string content, int size = 12) = 0;
};

#endif //DOODLEJUMP_WRAPPERFACTORY_H
