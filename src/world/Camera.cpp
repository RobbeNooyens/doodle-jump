//
// Created by robbe on 20/11/2021.
//

#include "Camera.h"

#include "../events/Event.h"
#include "../events/HeightChangedEvent.h"

double Camera::getHeight() const {
    return height;
}

void Camera::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == GameEventType::HEIGHT_CHANGED) {
        this->height += std::static_pointer_cast<HeightChangedEvent>(event)->getDifference();
    }
}
