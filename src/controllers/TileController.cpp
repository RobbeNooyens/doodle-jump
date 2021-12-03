//
// Created by robnoo on 25/11/21.
//

#include "TileController.h"
#include "../models/TileModel.h"
#include "../views/TileView.h"

controllers::TileController::TileController(): EntityController() {
    model = std::make_shared<models::TileModel>();
    view = std::make_shared<views::TileView>();
}

void controllers::TileController::handle(std::shared_ptr<Event> &event) {

}
