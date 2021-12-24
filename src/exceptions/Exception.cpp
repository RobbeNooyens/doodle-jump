//
// Created by robnoo on 24/12/21.
//

#include "Exception.h"

#include <utility>

const char *Exception::what() const noexcept {
    return message.c_str();
}

Exception::Exception(std::string message): message(std::move(message)) {

}
