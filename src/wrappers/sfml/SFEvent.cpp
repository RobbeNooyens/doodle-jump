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

#include "SFEvent.h"

sf::Event &wrappers::sfml::SFEvent::getEvent() {
    return event;
}

WindowEventType wrappers::sfml::SFEvent::getType() {
    switch (event.type) {
        case sf::Event::KeyReleased:
            return WindowEventType::KEY_RELEASED;
        case sf::Event::Closed:
            return WindowEventType::WINDOW_CLOSED;
        default:
            return WindowEventType::UNDEFINED_WINDOW_EVENT;
    }
}

bool wrappers::sfml::SFEvent::isKeyPressed(Keyboard key) {
    if(key == UNDEFINED_KEYBOARD_KEY)
        return false;
    sf::Keyboard::Key sfKey;
    switch (key) {
        case A:
            sfKey = sf::Keyboard::A;
            break;
        case D:
            sfKey = sf::Keyboard::D;
            break;
        case SPACEBAR:
            sfKey = sf::Keyboard::Space;
            break;
        case ARROW_LEFT:
            sfKey = sf::Keyboard::Left;
            break;
        case ARROW_RIGHT:
            sfKey = sf::Keyboard::Right;
            break;
    }
    return sf::Keyboard::isKeyPressed(sfKey);
}

Keyboard wrappers::sfml::SFEvent::getKey() {
    switch (event.key.code) {
        case sf::Keyboard::Space:
            return Keyboard::SPACEBAR;
        default:
            return Keyboard::UNDEFINED_KEYBOARD_KEY;
    }
}
