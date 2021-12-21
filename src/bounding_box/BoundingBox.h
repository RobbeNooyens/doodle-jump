//
// Created by robnoo on 21/12/21.
//

#ifndef DOODLEJUMP_BOUNDINGBOX_H
#define DOODLEJUMP_BOUNDINGBOX_H


#include <utility>

class BoundingBox {
public:
    BoundingBox(double left, double top, double right, double bottom);
    BoundingBox(double left, double top, double right, double bottom, std::pair<double, double> center);
    bool collides(BoundingBox& box) const;

    // Setters


    // Getters
    std::pair<double, double>& getCenter();
    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
    [[nodiscard]] double getTop() const;
    [[nodiscard]] double getBottom() const;
    [[nodiscard]] double getLeft() const;
    [[nodiscard]] double getRight() const;

private:
    double left, right, top, bottom;
    std::pair<double, double> center;
};


#endif //DOODLEJUMP_BOUNDINGBOX_H
