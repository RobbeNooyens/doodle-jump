//
// Created by robnoo on 8/01/22.
//

#ifndef DOODLEJUMP_FILENOTFOUNDEXCEPTION_H
#define DOODLEJUMP_FILENOTFOUNDEXCEPTION_H


#include <string>
#include "Exception.h"

namespace exceptions {
    class FileNotFoundException : public Exception {
    public:
        explicit FileNotFoundException(const std::string& fileName): Exception("File not found: " + fileName){};
    };
}


#endif //DOODLEJUMP_FILENOTFOUNDEXCEPTION_H
