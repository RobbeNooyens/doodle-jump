//
// Created by robnoo on 21/12/21.
//

#ifndef DOODLEJUMP_BOUNDINGBOX_H
#define DOODLEJUMP_BOUNDINGBOX_H


#include <utility>
#include <memory>

class BoundingBox {
public:
    BoundingBox();
    BoundingBox(double left, double top, double right, double bottom);
    bool collides(std::shared_ptr<BoundingBox>& box) const;

    // Setters
    void setBorder(double left, double top, double right, double bottom);
    void setCenter(std::pair<double, double> center);
    void calculateCenter();

    // Getters
    std::pair<double, double>& getCenter();
    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
    [[nodiscard]] double getTop() const;
    [[nodiscard]] double getBottom() const;
    [[nodiscard]] double getLeft() const;
    [[nodiscard]] double getRight() const;

    BoundingBox copy();

private:
    double left, right, top, bottom;
    std::pair<double, double> center;
};


#endif //DOODLEJUMP_BOUNDINGBOX_H
