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

#ifndef DOODLEJUMP_TEXTCONTROLLER_H
#define DOODLEJUMP_TEXTCONTROLLER_H


#include <string>
#include <memory>

class TextView;

namespace wrappers {
    class WindowWrapper;
    class TextWrapper;
}

namespace controllers {
    /**
     * @brief Represents a text
     */
    class TextController {
    public:
        /**
         * @brief Default constructor
         */
        TextController();
        /**
         * @brief Default destructor
         */
        ~TextController();

        /**
         * @brief Sets the stringcontent to the given string
         * @param s string to dipslay
         */
        void update(const std::string& s);
        /**
         * @brief Draws the current text to the window
         * @param window window to draw the text on
         */
        void draw(std::shared_ptr<wrappers::WindowWrapper> &window);

        /**
         * @param x new x position
         * @param y new y position
         */
        void setPosition(double x, double y);
        /**
         * @param wrapper textwrapper to use for rendering
         */
        void setTextWrapper(std::shared_ptr<wrappers::TextWrapper> &wrapper);

    private:
        std::shared_ptr<TextView> view;
    };
}


#endif //DOODLEJUMP_TEXTCONTROLLER_H
