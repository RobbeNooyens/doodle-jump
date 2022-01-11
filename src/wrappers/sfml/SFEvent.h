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

#ifndef DOODLEJUMP_SFEVENT_H
#define DOODLEJUMP_SFEVENT_H


#include <SFML/Window/Event.hpp>
#include "../EventWrapper.h"

namespace wrappers::sfml {

    /**
     * @brief SFML wrapper for a GUI event
     */
    class SFEvent : public EventWrapper {
    public:
        // Checking
        /**
         * @brief Checks if key is being pressed
         * @param key key to check
         * @return true if the given key is being pressed
         */
        bool isKeyPressed(Keyboard key) override;

        // Getters
        /**
         * @return wrapped SFML event
         */
        sf::Event &getEvent();
        /**
         * @return event type
         */
        WindowEventType getType() override;
        /**
         * @return key being pressed if event is keypress
         */
        Keyboard getKey() override;

    private:
        sf::Event event{};

    };

}


#endif //DOODLEJUMP_SFEVENT_H
