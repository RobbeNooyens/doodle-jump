//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include <utility>
#include <memory>

class EntityController;
class BoundingBox;

class EntityModel {
public:
    EntityModel();

    // Actions
    virtual void update(double elapsed) = 0;

    // TODO: check usage
    void updateBoundingBox();

    // Getters
    double getX();
    double getY();
    std::shared_ptr<BoundingBox> getBoundingBox();

    // Setters
    void setSize(double size);
    void setPosition(double x, double y);
    void setWidth(double w);
    void setHeight(double h);
    void setRelativeBBox(const std::shared_ptr<BoundingBox>& bbox);

protected:
    double size = 1, sizeY = 1;
    double width=1, height=1;
    double x = 0, y = 0;
    std::shared_ptr<BoundingBox> relativeBBox;
    std::shared_ptr<BoundingBox> absoluteBBox;
    std::weak_ptr<EntityController> controller;

};


#endif //DOODLEJUMP_ENTITYMODEL_H
