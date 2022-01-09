//
// Created by robnoo on 24/12/21.
//

#ifndef DOODLEJUMP_EXCEPTION_H
#define DOODLEJUMP_EXCEPTION_H

#include <exception>
#include <string>

namespace exceptions {

    class Exception : public std::exception {
    public:
        explicit Exception(std::string message): message(std::move(message)) {}

        [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
            return message.c_str();
        }

    private:
        std::string message;

    };

}


#endif //DOODLEJUMP_EXCEPTION_H
