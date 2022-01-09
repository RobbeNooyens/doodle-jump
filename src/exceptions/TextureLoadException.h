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

#ifndef DOODLEJUMP_TEXTURELOADEXCEPTION_H
#define DOODLEJUMP_TEXTURELOADEXCEPTION_H

#include "Exception.h"

namespace exceptions {
    /**
     * @brief Exception thrown when a texture wasn't able to load
     */
    class TextureLoadException: public Exception {
    public:
        /**
         * @brief Parameter constructor
         * @param textureFile file containing the texture
         */
        explicit TextureLoadException(const std::string& textureFile):
                Exception("Failed to load texture: " + textureFile) {};
    };
}

#endif //DOODLEJUMP_TEXTURELOADEXCEPTION_H
