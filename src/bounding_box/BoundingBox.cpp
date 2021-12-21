//
// Created by robnoo on 21/12/21.
//

#include "BoundingBox.h"

#include <utility>

bool BoundingBox::collides(BoundingBox &box) const {
    // Source: https://www.geeksforgeeks.org/find-two-rectangles-overlap/

    // the line cannot have positive overlap
    if (left == right || top == bottom || box.left == box.right || box.top == box.bottom)
        return false;

    // If one rectangle is on left side of other
    if (left >= box.right || box.left >= right)
        return false;

    // If one rectangle is above other
    if (bottom <= box.top || box.bottom <= top)
        return false;

    return true;
}

double BoundingBox::getTop() const {
    return top;
}

double BoundingBox::getBottom() const {
    return bottom;
}

double BoundingBox::getLeft() const {
    return left;
}

double BoundingBox::getRight() const {
    return right;
}

double BoundingBox::getWidth() const {
    return right - left;
}

double BoundingBox::getHeight() const {
    return bottom - top;
}

BoundingBox::BoundingBox(double l, double t, double r, double b): left(l), top(t), right(r), bottom(b), center({(right - left) / 2, (bottom - top) / 2}) {}

BoundingBox::BoundingBox(double left, double top, double right, double bottom, std::pair<double, double> center): left(left), top(top), right(right), bottom(bottom), center(std::move(center)) {}

std::pair<double, double> &BoundingBox::getCenter() {
    return center;
}
