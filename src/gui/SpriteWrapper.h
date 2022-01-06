//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SPRITEWRAPPER_H
#define DOODLEJUMP_SPRITEWRAPPER_H

#include <string>

class TextureWrapper;

class SpriteWrapper {
public:
    virtual const std::shared_ptr<TextureWrapper>& getTexture() = 0;
    virtual void setTexture(const std::string &identifier) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setScale(float factorX, float factorY) = 0;
};

#endif //DOODLEJUMP_SPRITEWRAPPER_H
