//
// Created by robnoo on 28/11/21.
//

#include "KeyPressedEvent.h"

events::KeyPressedEvent::KeyPressedEvent(Keyboard key): Event(GameEventType::KEY_PRESSED), keyPressed(key) {}

Keyboard events::KeyPressedEvent::getKey() {
    return keyPressed;
}
