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

#ifndef DOODLEJUMP_FONTLOADEXCEPTION_H
#define DOODLEJUMP_FONTLOADEXCEPTION_H

#include "Exception.h"

namespace exceptions {
    /**
     * @brief Exception thrown when a font wasn't able to load
     */
    class FontLoadException: public Exception {
    public:
        /**
         * @brief Parameter constructor
         * @param fontFile file in which the font is located
         */
        explicit FontLoadException(const std::string& fontFile):
        Exception("Failed to load font: " + fontFile) {};
    };
}

#endif //DOODLEJUMP_FONTLOADEXCEPTION_H
