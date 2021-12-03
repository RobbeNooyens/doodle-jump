//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include <utility>
#include <memory>
#include "../controllers/EntityController.h"

class BoundingBox;

class EntityModel {
public:
    // Actions
    virtual void update(double elapsed) = 0;
    void moveTo(double x, double y);

    // Getters
    double getX();
    double getY();
    std::pair<double, double> getCoordinates();
    std::pair<double, double> getUpperLeftCorner();
    std::pair<std::pair<double, double>, std::pair<double, double>> getBox();

    // Setters
    void setSize(double size);
    void setBoundingBox(std::shared_ptr<BoundingBox>& bbox);
    void setWidth(double w);
    void setHeight(double h);
    void setController(std::shared_ptr<EntityController> controller);

protected:
    double size = 1, sizeY = 1;
    double width=1, height=1;
    double x = 0, y = 0;
    std::shared_ptr<BoundingBox> bbox;
    std::weak_ptr<EntityController> controller;





};


#endif //DOODLEJUMP_ENTITYMODEL_H
