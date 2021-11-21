//
// Created by robbe on 21/11/2021.
//

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

struct Position {
    double x, y;
};

struct BoundingBox {
    double top, bottom, left, right;
};

enum EntityType {
    BONUS, PLAYER, PLATFORM
};

class EntityModel {
public:


private:
    Position position;
    BoundingBox boundingBox;
    EntityType type;

};


#endif //DOODLEJUMP_ENTITYMODEL_H
