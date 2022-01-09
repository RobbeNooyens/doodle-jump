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

#include "KeyPressedEvent.h"

events::KeyPressedEvent::KeyPressedEvent(Keyboard key): Event(GameEventType::KEY_PRESSED), keyPressed(key) {}

Keyboard events::KeyPressedEvent::getKey() {
    return keyPressed;
}
