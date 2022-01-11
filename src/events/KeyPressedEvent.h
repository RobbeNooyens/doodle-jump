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

#ifndef DOODLEJUMP_KEYPRESSEDEVENT_H
#define DOODLEJUMP_KEYPRESSEDEVENT_H


#include "Event.h"
#include "../enums/Keyboard.h"

namespace events {

    /**
     * @brief Represents an event when a key is pressed on an input device
     */
    class KeyPressedEvent : public Event {
    public:
        /**
         * @brief Parameter constructor
         * @param key key being pressed
         */
        explicit KeyPressedEvent(Keyboard key);

        /**
         * @return the key that was pressed
         */
        Keyboard getKey();

    private:
        Keyboard keyPressed = Keyboard::UNDEFINED_KEYBOARD_KEY;
    };

}


#endif //DOODLEJUMP_KEYPRESSEDEVENT_H
