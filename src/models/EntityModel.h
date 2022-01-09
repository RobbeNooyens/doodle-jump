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

#ifndef DOODLEJUMP_ENTITYMODEL_H
#define DOODLEJUMP_ENTITYMODEL_H

#include <utility>
#include <memory>

class EntityController;
class BoundingBox;

/**
 * @brief Represents the backend of an entity
 */
class EntityModel {
public:
    // Constructor - Destructor
    /**
     * @brief Default constructor
     */
    EntityModel();
    /**
     * @brief Virtual destructor
     */
    virtual ~EntityModel();

    // Actions
    /**
     * @brief Update model based on the elapsed time
     * @param elapsed elapsed seconds since last frame
     */
    virtual void update(double elapsed) = 0;
    /**
     * @brief Updates the model's bounds
     */
    void updateBoundingBox();

    // Getters
    /**
     * @return logic x coordinate
     */
    double getX();
    /**
     * @return logic y coordinate
     */
    double getY();
    /**
     * @return model's bounding box
     */
    std::shared_ptr<BoundingBox> getBoundingBox();

    // Setters
    /**
     * @param size width to scale the entity to
     */
    void setSize(double size);
    /**
     * @param x new x coordinate
     * @param y new y coordinate
     */
    void setPosition(double x, double y);
    /**
     * @param w image width used for scaling
     */
    void setWidth(double w);
    /**
     * @param h image height used for scaling
     */
    void setHeight(double h);
    /**
     * @param bbox texture bounding box
     */
    void setRelativeBBox(const std::shared_ptr<BoundingBox>& bbox);

protected:
    /**
     * @brief scaled width
     */
    double size = 1;
    /**
     * @brief scaled height
     */
    double sizeY = 1;
    /**
     * @brief texture width
     */
    double width=1;
    /**
     * @brief texture height
     */
    double height=1;
    /**
     * @brief x coordinate
     */
    double x = 0;
    /**
     * @brief y coordinate
     */
    double y = 0;
    /**
     * @brief texture bounding box
     */
    std::shared_ptr<BoundingBox> relativeBBox;
    /**
     * @brief model bounding box
     */
    std::shared_ptr<BoundingBox> absoluteBBox;
};


#endif //DOODLEJUMP_ENTITYMODEL_H
