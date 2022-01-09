//
// Created by robnoo on 6/01/22.
//

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
