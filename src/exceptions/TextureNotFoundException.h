//
// Created by robnoo on 24/12/21.
//

#ifndef DOODLEJUMP_TEXTURENOTFOUNDEXCEPTION_H
#define DOODLEJUMP_TEXTURENOTFOUNDEXCEPTION_H


#include "Exception.h"

namespace exceptions {
    class TextureNotFoundException : public Exception {
    public:
        explicit TextureNotFoundException(const std::string& spriteId, const std::string& textureId):
        Exception("Texture not found: sprite = " + spriteId + ", texture = " + textureId) {};

    };
}


#endif //DOODLEJUMP_TEXTURENOTFOUNDEXCEPTION_H
