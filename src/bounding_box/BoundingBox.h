/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#ifndef DOODLEJUMP_BOUNDINGBOX_H
#define DOODLEJUMP_BOUNDINGBOX_H

#include <utility>
#include <memory>

/**
 * @brief Represents a bounding box for entities and textures
 */
class BoundingBox {
public:
    /**
     * @brief Default constructor
     */
    BoundingBox();
    /**
     * @brief Parametered constructor
     * @param left leftbound
     * @param top upperbound
     * @param right rightbound
     * @param bottom lowerbound
     */
    BoundingBox(double left, double top, double right, double bottom);

    /**
     * @brief Checks whether this bounding box collides with the given box or not
     * @param box other box to check collision with
     * @return true if this bounding box collides with the other box
     */
    bool collides(std::shared_ptr<BoundingBox>& box) const;
    /**
     * @brief Calculates the center by taken the middle of the x values and the middle of the y values
     */
    void calculateCenter();

    // Setters
    /**
     * @brief Sets the boundings to the given values
     * @param left leftbound
     * @param top upperbound
     * @param right rightbound
     * @param bottom lowerbound
     */
    void setBorder(double left, double top, double right, double bottom);
    /**
     * @brief Sets the center of this bounding box explicitly
     * @param center double pair containing the x and y value of the center
     */
    void setCenter(std::pair<double, double> center);

    // Getters
    /**
     * @return bounding box center
     */
    [[nodiscard]] const std::pair<double, double>& getCenter() const;
    /**
     * @return bounding box width
     */
    [[nodiscard]] double getWidth() const;
    /**
     * @return bounding box height
     */
    [[nodiscard]] double getHeight() const;
    /**
     * @return bounding box upperbound
     */
    [[nodiscard]] double getTop() const;
    /**
     * @return bounding box lower-bound
     */
    [[nodiscard]] double getBottom() const;
    /**
     * @return bounding box left-bound
     */
    [[nodiscard]] double getLeft() const;
    /**
     * @return bounding box right-bound
     */
    [[nodiscard]] double getRight() const;

private:
    double left=0, right=0, top=0, bottom=0;
    std::pair<double, double> center{};
};


#endif //DOODLEJUMP_BOUNDINGBOX_H
