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
