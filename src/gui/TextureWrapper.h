//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_TEXTUREWRAPPER_H
#define DOODLEJUMP_TEXTUREWRAPPER_H

#include <string>
#include <memory>

class BoundingBox;

class TextureWrapper {
public:
    virtual void loadFromFile(std::string& file) = 0;

    virtual const std::shared_ptr<BoundingBox>& getBoundingBox() = 0;
    virtual double getWidth() = 0;
    virtual double getHeight() = 0;

};

#endif //DOODLEJUMP_TEXTUREWRAPPER_H
