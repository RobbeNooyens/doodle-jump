//
// Created by robnoo on 24/12/21.
//

#ifndef DOODLEJUMP_EXCEPTION_H
#define DOODLEJUMP_EXCEPTION_H


#include <exception>
#include <string>

class Exception: public std::exception {
public:
    explicit Exception(std::string message);
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

private:
    std::string message;

};


#endif //DOODLEJUMP_EXCEPTION_H
