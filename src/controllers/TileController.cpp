//
// Created by robnoo on 25/11/21.
//

#include "TileController.h"
#include "../models/TileModel.h"
#include "../views/TileView.h"
#include "../events/HeightChangedEvent.h"

controllers::TileController::TileController(): EntityController() {
    model = std::make_shared<models::TileModel>();
    view = std::make_shared<views::TileView>();
}

void controllers::TileController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == HEIGHT_CHANGED) {
        std::shared_ptr<HeightChangedEvent> heightEvent = std::static_pointer_cast<HeightChangedEvent>(event);
        this->changeY(heightEvent->getDifference()/2);
    }
}

void controllers::TileController::recycle() {
    this->setDestroyed(false);
    std::static_pointer_cast<models::TileModel>(model)->recycle();
}
