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

#ifndef DOODLEJUMP_FILENOTFOUNDEXCEPTION_H
#define DOODLEJUMP_FILENOTFOUNDEXCEPTION_H

#include "Exception.h"

namespace exceptions {
    class FileNotFoundException : public Exception {
    public:
        explicit FileNotFoundException(const std::string& fileName): Exception("File not found: " + fileName){};
    };
}


#endif //DOODLEJUMP_FILENOTFOUNDEXCEPTION_H
