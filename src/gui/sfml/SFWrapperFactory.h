//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFWRAPPERFACTORY_H
#define DOODLEJUMP_SFWRAPPERFACTORY_H


#include "../WrapperFactory.h"

class SFWrapperFactory: public WrapperFactory {
public:
    std::shared_ptr<SpriteWrapper> loadSprite() override;


    std::shared_ptr<WindowWrapper>
    loadWindow(const std::string &applicationName, unsigned int width, unsigned int height) override;

    std::shared_ptr<TextWrapper> loadText(std::string& content, int size) override;

    std::shared_ptr<TextureWrapper>
    loadTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) override;

};


#endif //DOODLEJUMP_SFWRAPPERFACTORY_H
