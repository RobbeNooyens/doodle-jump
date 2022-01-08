//
// Created by robnoo on 9/01/22.
//

#ifndef DOODLEJUMP_FONTLOADEXCEPTION_H
#define DOODLEJUMP_FONTLOADEXCEPTION_H

#include "Exception.h"

namespace exceptions {
    class FontLoadException: public Exception {
    public:
        explicit FontLoadException(const std::string& fontFile):
        Exception("Failed to load font: " + fontFile) {};
    };
}

#endif //DOODLEJUMP_FONTLOADEXCEPTION_H
