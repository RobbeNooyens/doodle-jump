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

class Camera: public EventHandler {
public:
    [[nodiscard]] double getHeight() const;

    void handle(std::shared_ptr<events::Event> &event) override;

private:
    double height = 0;
};


#endif //DOODLEJUMP_CAMERA_H
