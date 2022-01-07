//
// Created by robnoo on 25/11/21.
//

#include "TileModel.h"
#include "../bounding_box/BoundingBox.h"

models::TileModel::TileModel(std::shared_ptr<EntityController> controller): EntityModel(controller) {

}

void models::TileModel::update(double elapsed) {

}

void models::TileModel::recycle() {
    this->y = -getBoundingBox()->getHeight()/2;
}
