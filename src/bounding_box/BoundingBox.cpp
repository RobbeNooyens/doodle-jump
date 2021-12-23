//
// Created by robnoo on 21/12/21.
//

#include "BoundingBox.h"

#include <utility>

bool BoundingBox::collides(std::shared_ptr<BoundingBox> &box) const {
    // Source: https://www.geeksforgeeks.org/find-two-rectangles-overlap/

    // the line cannot have positive overlap
    if (left == right || top == bottom || box->left == box->right || box->top == box->bottom)
        return false;

    // If one rectangle is on left side of other
    if (left >= box->right || box->left >= right)
        return false;

    // If one rectangle is above other
    if (bottom <= box->top || box->bottom <= top)
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

BoundingBox::BoundingBox(double l, double t, double r, double b): left(l), top(t), right(r), bottom(b) {
    calculateCenter();
}

std::pair<double, double> &BoundingBox::getCenter() {
    return center;
}

void BoundingBox::setBorder(double left, double top, double right, double bottom) {
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
}

void BoundingBox::setCenter(std::pair<double, double> center) {
    this->center = std::move(center);
}

void BoundingBox::calculateCenter() {
    this->center = {(left + right) / 2, (bottom + top) / 2};
}

BoundingBox::BoundingBox(): left(0), top(0), right(0), bottom(0) {

}

BoundingBox BoundingBox::copy() {
    BoundingBox box{left, top, right, bottom};
    box.setCenter(center);
    return box;
}
