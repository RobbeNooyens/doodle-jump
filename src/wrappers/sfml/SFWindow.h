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

#ifndef DOODLEJUMP_SFWINDOW_H
#define DOODLEJUMP_SFWINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "../WindowWrapper.h"

namespace wrappers::sfml {

    /**
     * @brief SFML wrapper for a GUI window
     */
    class SFWindow : public WindowWrapper {
    public:
        // Construtor
        /**
         * @brief Constructor
         * @param applicationName application name
         * @param width window witdh in pixels
         * @param height window height in pixels
         */
        SFWindow(const std::string &applicationName, unsigned int width, unsigned int height);

        // Forwarding calls
        /**
         * @return true if the window is opened
         */
        bool isOpen() override;
        /**
         * @brief Clear the window
         */
        void clear() override;
        /**
         * @brief Display the window
         */
        void display() override;
        /**
         * Check if there are events waiting to be handled
         * @param event event waiting for handling
         * @return true if the event queue has events
         */
        bool pollEvent(std::shared_ptr<EventWrapper> &event) override;
        /**
         * @brief Draws a sprite in the window
         * @param sprite sprite to display
         */
        void draw(const std::shared_ptr<SpriteWrapper> &sprite) override;
        /**
         * @brief Draws text in the window
         * @param text text to display
         */
        void draw(const std::shared_ptr<TextWrapper> &text) override;

    private:
        sf::RenderWindow window{};

    };

}


#endif //DOODLEJUMP_SFWINDOW_H
