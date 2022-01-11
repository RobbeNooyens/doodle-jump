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

#ifndef DOODLEJUMP_EVENTWRAPPER_H
#define DOODLEJUMP_EVENTWRAPPER_H

#include "../enums/WindowEventType.h"
#include "../enums/Keyboard.h"

namespace wrappers {

    /**
     * @brief Wrapper for a GUI event
     */
    class EventWrapper {
    public:
        /**
         * @return event type
         */
        virtual WindowEventType getType() = 0;

        /**
         * @brief Checks if a key is being pressed
         * @param key key to check
         * @return true if the given key is being pressed
         */
        virtual bool isKeyPressed(Keyboard key) = 0;

        /**
         * @return the key if an event related to keyboard input is invoked
         */
        virtual Keyboard getKey() = 0;

    };

}

#endif //DOODLEJUMP_EVENTWRAPPER_H
