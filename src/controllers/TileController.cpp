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

#include "TileController.h"
#include "../models/TileModel.h"
#include "../views/TileView.h"
#include "../events/HeightChangedEvent.h"

controllers::TileController::TileController(): EntityController() {
    model = std::make_shared<models::TileModel>();
    view = std::make_shared<views::TileView>();
}

void controllers::TileController::handle(std::shared_ptr<events::Event> &event) {
    if(event->getType() == HEIGHT_CHANGED) {
        std::shared_ptr<events::HeightChangedEvent> heightEvent = std::static_pointer_cast<events::HeightChangedEvent>(event);
        this->changeY(heightEvent->getDifference()/2);
    }
}

void controllers::TileController::goesBeneathScreen() {
    this->setDestroyed(false);
    std::static_pointer_cast<models::TileModel>(model)->recycle();
}
