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

#ifndef DOODLEJUMP_PARSEEXCEPTION_H
#define DOODLEJUMP_PARSEEXCEPTION_H


#include "Exception.h"

namespace exceptions {
    class ParseException : public Exception {
    public:
        ParseException(const std::string& fileName, const std::string& message):
        Exception("Parse error in " + fileName + ": " + message){};
    };
}


#endif //DOODLEJUMP_PARSEEXCEPTION_H
