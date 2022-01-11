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

#include "TileModel.h"
#include "../bounding_box/BoundingBox.h"

models::TileModel::TileModel(): EntityModel() {}

void models::TileModel::update(double elapsed) {}

void models::TileModel::recycle() {
    this->y = -getBoundingBox()->getHeight()/2;
}
