//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SPRITEWRAPPER_H
#define DOODLEJUMP_SPRITEWRAPPER_H


#include <string>
#include "TextureWrapper.h"

class SpriteWrapper {
public:
    virtual void addTexture(std::string& identifier, std::shared_ptr<TextureWrapper>& texture) = 0;
    virtual void applyTexture(std::string& identifier) = 0;


};

#endif //DOODLEJUMP_SPRITEWRAPPER_H
