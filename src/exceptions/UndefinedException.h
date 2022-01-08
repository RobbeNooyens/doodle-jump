//
// Created by robnoo on 8/01/22.
//

#ifndef DOODLEJUMP_UNDEFINEDEXCEPTION_H
#define DOODLEJUMP_UNDEFINEDEXCEPTION_H

#include "Exception.h"

#include <string>

namespace exceptions {
    class UndefinedException: public Exception {
    public:
        explicit UndefinedException(const std::string& what): Exception(what) {};
    };
}


#endif //DOODLEJUMP_UNDEFINEDEXCEPTION_H
