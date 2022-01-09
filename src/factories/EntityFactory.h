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

#ifndef DOODLEJUMP_ENTITYFACTORY_H
#define DOODLEJUMP_ENTITYFACTORY_H

#include <memory>
#include "../enums/PlatformType.h"
#include "../enums/BonusType.h"

namespace controllers {
    class PlatformController;
    class PlayerController;
    class BonusController;
    class TileController;
    class TextController;
}

class EntityFactory {
public:
    virtual std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) = 0;
    virtual std::shared_ptr<controllers::PlayerController> loadPlayer() = 0;
    virtual std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) = 0;
    virtual std::shared_ptr<controllers::TileController> loadTile() = 0;
    virtual std::shared_ptr<controllers::TextController> loadText(std::basic_string<char> text, unsigned int fontSize) = 0;
};


#endif //DOODLEJUMP_ENTITYFACTORY_H
