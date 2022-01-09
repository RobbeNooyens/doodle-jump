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

    class SFEvent : public EventWrapper {
    public:
        // Checking
        bool isKeyPressed(Keyboard key) override;

        // Getters
        sf::Event &getEvent();

        WindowEventType getType() override;

        Keyboard getKey() override;

    private:
        sf::Event event{};

    };

}


#endif //DOODLEJUMP_SFEVENT_H
