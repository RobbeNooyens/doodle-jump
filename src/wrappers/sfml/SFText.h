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

#ifndef DOODLEJUMP_SFTEXT_H
#define DOODLEJUMP_SFTEXT_H

#include "../TextWrapper.h"
#include <SFML/Graphics/Text.hpp>

namespace sf {
    class Font;
}

namespace wrappers::sfml {

    /**
     * @brief SFML wrapper for a text element
     */
    class SFText : public TextWrapper {
    public:
        /**
         * @brief Parameter constructor
         * @param content string to display
         * @param size font size
         */
        SFText(const std::string &content, unsigned int size);
        /**
         * @param x set x coordinate
         * @param y set y coordinate
         */
        void setPosition(float x, float y) override;
        /**
         * @return wrapped SFML Text object
         */
        sf::Text &getText();
        /**
         * @param text text to display
         */
        void setText(const std::string &text) override;

    private:
        static sf::Font font;
        static bool fontInitialized;
        sf::Text text{};

    };

}

#endif //DOODLEJUMP_SFTEXT_H
