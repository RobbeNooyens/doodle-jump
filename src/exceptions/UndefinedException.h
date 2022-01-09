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
    /**
     * @brief Exception thrown when an exception other than the custom defined ones has been thrown
     */
    class UndefinedException: public Exception {
    public:
        /**
         * @brief Parameter constructor
         * @param what descriptive error message
         */
        explicit UndefinedException(const std::string& what): Exception(what) {};
    };
}


#endif //DOODLEJUMP_UNDEFINEDEXCEPTION_H
