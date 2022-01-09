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

#ifndef DOODLEJUMP_TEXTWRAPPER_H
#define DOODLEJUMP_TEXTWRAPPER_H

#include <string>

namespace wrappers {

    class TextWrapper {
    public:
        virtual void setText(const std::string &text) = 0;

        virtual void setPosition(float x, float y) = 0;

    };

}

#endif //DOODLEJUMP_TEXTWRAPPER_H
