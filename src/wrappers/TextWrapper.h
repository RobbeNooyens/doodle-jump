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

#ifndef DOODLEJUMP_TEXTWRAPPER_H
#define DOODLEJUMP_TEXTWRAPPER_H

#include <string>

namespace wrappers {

    /**
     * @brief Wrapper for a text object
     */
    class TextWrapper {
    public:
        /**
         * @brief Sets the text to display to the given text
         * @param text text to display
         */
        virtual void setText(const std::string &text) = 0;

        /**
         * @param x new x coordinate
         * @param y new y coordinate
         */
        virtual void setPosition(float x, float y) = 0;

    };

}

#endif //DOODLEJUMP_TEXTWRAPPER_H
