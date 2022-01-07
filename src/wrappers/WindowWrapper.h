//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_WINDOWWRAPPER_H
#define DOODLEJUMP_WINDOWWRAPPER_H


#include <string>

class TextWrapper;
class EventWrapper;
class SpriteWrapper;

class WindowWrapper {
public:
    virtual void draw(const std::shared_ptr<SpriteWrapper> &sprite) = 0;
    virtual void draw(const std::shared_ptr<TextWrapper>& text) = 0;
    virtual bool isOpen() = 0;
    virtual void clear() = 0;
    virtual void display() = 0;
    virtual bool pollEvent(std::shared_ptr<EventWrapper>& event) = 0;


};


#endif //DOODLEJUMP_WINDOWWRAPPER_H