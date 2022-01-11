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

#ifndef DOODLEJUMP_WINDOWWRAPPER_H
#define DOODLEJUMP_WINDOWWRAPPER_H


#include <string>

namespace wrappers {
    class TextWrapper;

    class EventWrapper;

    class SpriteWrapper;
}

namespace wrappers {

    /**
     * @brief Wrapper for a window object
     */
    class WindowWrapper {
    public:
        /**
         * @brief Draws a sprite in a window
         * @param sprite sprite to draw
         */
        virtual void draw(const std::shared_ptr<wrappers::SpriteWrapper> &sprite) = 0;

        /**
         * @brief Draws a text object in a window
         * @param text text to draw
         */
        virtual void draw(const std::shared_ptr<wrappers::TextWrapper> &text) = 0;

        /**
         * @return true if the window is open
         */
        virtual bool isOpen() = 0;

        /**
         * @brief Clears the content of the window
         */
        virtual void clear() = 0;

        /**
         * @brief Updates and displays the window contents
         */
        virtual void display() = 0;

        /**
         * @brief Checks for Gui events and passes them in a wrapper
         * @param event GUI event invoked by the GUI library
         * @return true if an event is available
         */
        virtual bool pollEvent(std::shared_ptr<wrappers::EventWrapper> &event) = 0;


    };

}

#endif //DOODLEJUMP_WINDOWWRAPPER_H
