//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include <utility>
#include <memory>

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

    // Setters
    void setSize(double size);

protected:
    double size = 1;
    double x = 0, y = 0;
    std::shared_ptr<BoundingBox> bbox;





};


#endif //DOODLEJUMP_ENTITYMODEL_H
