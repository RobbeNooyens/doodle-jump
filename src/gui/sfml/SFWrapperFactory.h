//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFWRAPPERFACTORY_H
#define DOODLEJUMP_SFWRAPPERFACTORY_H


#include "../WrapperFactory.h"

class SFWrapperFactory: public WrapperFactory {
public:
    std::shared_ptr<SpriteWrapper> createSprite() override;


    std::shared_ptr<WindowWrapper>
    createWindow(const std::string &applicationName, unsigned int width, unsigned int height) override;

    std::shared_ptr<TextWrapper> createText(std::string& content, unsigned int size) override;

    std::shared_ptr<TextureWrapper>
    createTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) override;

    std::shared_ptr<EventWrapper> createEvent() override;

};


#endif //DOODLEJUMP_SFWRAPPERFACTORY_H
