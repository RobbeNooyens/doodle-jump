//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include <utility>
#include <memory>
#include "../controllers/EntityController.h"

class RelativeBoundingBox;

class EntityModel {
public:
    // Actions
    virtual void update(double elapsed) = 0;
    void moveTo(double x, double y);
    void updateAbsoluteBBox();

    // Getters
    double getX();
    double getY();
    std::shared_ptr<BoundingBox> getAbsoluteBBox();

    // Setters
    void setSize(double size);
    void setWidth(double w);
    void setHeight(double h);
    void setRelativeBBox(std::shared_ptr<BoundingBox>& bbox);
    void setController(std::shared_ptr<EntityController> controller);

protected:
    double size = 1, sizeY = 1;
    double width=1, height=1;
    double x = 0, y = 0;
    std::shared_ptr<BoundingBox> relativeBBox;
    std::shared_ptr<BoundingBox> absoluteBBox;
    std::weak_ptr<EntityController> controller;





};


#endif //DOODLEJUMP_ENTITYMODEL_H
