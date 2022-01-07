//
// Created by robnoo on 6/01/22.
//

#include "SFEvent.h"

sf::Event &SFEvent::getEvent() {
    return event;
}

WindowEventType SFEvent::getType() {
    switch (event.type) {
        case sf::Event::KeyReleased:
            return WindowEventType::KEY_RELEASED;
        case sf::Event::Closed:
            return WindowEventType::WINDOW_CLOSED;
        default:
            return WindowEventType::UNDEFINED_WINDOW_EVENT;
    }
}

bool SFEvent::isKeyPressed(Keyboard key) {
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
        default:
            // TODO: exception handling
            throw std::runtime_error("Invalid key input");
    }
    return sf::Keyboard::isKeyPressed(sfKey);
}

Keyboard SFEvent::getKey() {
    switch (event.key.code) {
        case sf::Keyboard::Space:
            return Keyboard::SPACEBAR;
        default:
            return Keyboard::UNDEFINED_KEYBOARD_KEY;
    }
}