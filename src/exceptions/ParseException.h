//
// Created by robnoo on 8/01/22.
//

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
