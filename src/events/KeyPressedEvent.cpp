//
// Created by robnoo on 28/11/21.
//

#include "KeyPressedEvent.h"

KeyPressedEvent::KeyPressedEvent(Keyboard key): Event(GameEventType::KEY_PRESSED), keyPressed(key) {}

Keyboard KeyPressedEvent::getKey() {
    return keyPressed;
}
