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

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H


#include "../events/EventHandler.h"

/**
 * @brief Keeps track of the camera height
 */
class Camera: public EventHandler {
public:
    /**
     * @return current camera height
     */
    [[nodiscard]] double getHeight() const;

    /**
     * @brief Handles incoming game events
     * @param event event that got invoked
     */
    void handle(std::shared_ptr<events::Event> &event) override;

private:
    double height = 0;
};


#endif //DOODLEJUMP_CAMERA_H
