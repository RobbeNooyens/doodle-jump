//
// Created by robnoo on 9/01/22.
//

#ifndef DOODLEJUMP_TEXTURELOADEXCEPTION_H
#define DOODLEJUMP_TEXTURELOADEXCEPTION_H

#include "Exception.h"

namespace exceptions {
    class TextureLoadException: public Exception {
    public:
        explicit TextureLoadException(const std::string& textureFile):
                Exception("Failed to load texture: " + textureFile) {};
    };
}

#endif //DOODLEJUMP_TEXTURELOADEXCEPTION_H
