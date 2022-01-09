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
    /**
     * @brief Exception thrown when an error occurs during the parsing of a file
     */
    class ParseException : public Exception {
    public:
        /**
         * @brief Parameter constructor
         * @param fileName name of the file that was being parsed
         * @param message descriptive error message
         */
        ParseException(const std::string& fileName, const std::string& message):
        Exception("Parse error in " + fileName + ": " + message){};
    };
}


#endif //DOODLEJUMP_PARSEEXCEPTION_H
