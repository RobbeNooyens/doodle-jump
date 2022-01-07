//
// Created by robnoo on 25/11/21.
//

#include "TileController.h"
#include "../models/TileModel.h"
#include "../views/TileView.h"
#include "../events/ReachedNewHeightEvent.h"

controllers::TileController::TileController(): EntityController() {
    model = std::make_shared<models::TileModel>(shared_from_this());
    view = std::make_shared<views::TileView>(shared_from_this());
}

void controllers::TileController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == REACHED_HEIGHT) {
        std::shared_ptr<ReachedNewHeightEvent> heightEvent = std::static_pointer_cast<ReachedNewHeightEvent>(event);
        this->changeY(heightEvent->getDifference()/2);
    }
}

void controllers::TileController::recycle() {
    this->setDestroyed(false);
    std::static_pointer_cast<models::TileModel>(model)->recycle();
}
