//
// Created by robnoo on 25/11/21.
//

#include "PlatformModel.h"

void models::HorizontalPlatform::update(double elapsed) {
    PlatformModel::update(elapsed);
}

void models::TemporaryPlatform::update(double elapsed) {
    PlatformModel::update(elapsed);
}

void models::VerticalPlatform::update(double elapsed) {
    PlatformModel::update(elapsed);
}

models::PlatformModel::PlatformModel(): EntityModel() {

}
