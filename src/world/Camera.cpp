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

#include "Camera.h"

#include "../events/Event.h"
#include "../events/HeightChangedEvent.h"

double Camera::getHeight() const {
    return height;
}

void Camera::handle(std::shared_ptr<events::Event> &event) {
    if(event->getType() == GameEventType::HEIGHT_CHANGED) {
        this->height += std::static_pointer_cast<events::HeightChangedEvent>(event)->getDifference();
    }
}
