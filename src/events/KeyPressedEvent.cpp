//
// Created by robnoo on 28/11/21.
//

#include "KeyPressedEvent.h"

KeyPressedEvent::KeyPressedEvent(KeyAction action): Event(EventType::KEY_PRESSED), action(action) {}

KeyAction KeyPressedEvent::getAction() {
    return action;
}
