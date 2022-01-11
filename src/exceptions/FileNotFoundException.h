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
    /**
     * @brief Exception thrown when a requested file is not found
     */
    class FileNotFoundException : public Exception {
    public:
        /**
         * @brief Parameter constructor
         * @param fileName name of the file
         */
        explicit FileNotFoundException(const std::string& fileName): Exception("File not found: " + fileName){};
    };
}


#endif //DOODLEJUMP_FILENOTFOUNDEXCEPTION_H
