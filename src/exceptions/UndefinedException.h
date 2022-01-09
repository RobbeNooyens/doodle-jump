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

#ifndef DOODLEJUMP_UNDEFINEDEXCEPTION_H
#define DOODLEJUMP_UNDEFINEDEXCEPTION_H

#include "Exception.h"

namespace exceptions {
    class UndefinedException: public Exception {
    public:
        explicit UndefinedException(const std::string& what): Exception(what) {};
    };
}


#endif //DOODLEJUMP_UNDEFINEDEXCEPTION_H
