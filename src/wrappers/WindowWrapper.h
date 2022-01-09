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

#ifndef DOODLEJUMP_WINDOWWRAPPER_H
#define DOODLEJUMP_WINDOWWRAPPER_H


#include <string>

namespace wrappers {
    class TextWrapper;

    class EventWrapper;

    class SpriteWrapper;
}

namespace wrappers {

    class WindowWrapper {
    public:
        virtual void draw(const std::shared_ptr<wrappers::SpriteWrapper> &sprite) = 0;

        virtual void draw(const std::shared_ptr<wrappers::TextWrapper> &text) = 0;

        virtual bool isOpen() = 0;

        virtual void clear() = 0;

        virtual void display() = 0;

        virtual bool pollEvent(std::shared_ptr<wrappers::EventWrapper> &event) = 0;


    };

}

#endif //DOODLEJUMP_WINDOWWRAPPER_H
