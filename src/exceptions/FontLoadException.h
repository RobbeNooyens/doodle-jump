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
    class FontLoadException: public Exception {
    public:
        explicit FontLoadException(const std::string& fontFile):
        Exception("Failed to load font: " + fontFile) {};
    };
}

#endif //DOODLEJUMP_FONTLOADEXCEPTION_H
