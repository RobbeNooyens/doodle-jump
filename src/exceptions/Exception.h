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

#ifndef DOODLEJUMP_EXCEPTION_H
#define DOODLEJUMP_EXCEPTION_H

#include <exception>
#include <string>

namespace exceptions {

    /**
     * @brief Represents an exception
     */
    class Exception : public std::exception {
    public:
        /**
         * @brief Parameter constructor
         * @param message message to display as part of the error message
         */
        explicit Exception(std::string message): message(std::move(message)) {}
        /**
         * @brief Default virtual destructor
         */
        ~Exception() override = default;

        /**
         * @return info message about the exception
         */
        [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
            return message.c_str();
        }

    private:
        std::string message{};

    };

}


#endif //DOODLEJUMP_EXCEPTION_H
