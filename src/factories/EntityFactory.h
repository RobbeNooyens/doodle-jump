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

/**
 * @brief Abstract factory to create new entities
 */
class EntityFactory {
public:
    /**
     * @brief Creates a new platform entity
     * @param platformType type of platform to create
     * @return smart pointer to the newly created platform
     */
    virtual std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) = 0;
    /**
     * @brief Creates a new player entity
     * @return smart pointer to the newly created player
     */
    virtual std::shared_ptr<controllers::PlayerController> loadPlayer() = 0;
    /**
     * @brief Creates a new bonus entity
     * @param bonusType type of bonus to create
     * @return smart pointer to the newly created bonus
     */
    virtual std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) = 0;
    /**
     * @brief Creates a new tile entity
     * @return smart pointer to the newly created tile
     */
    virtual std::shared_ptr<controllers::TileController> loadTile() = 0;
    /**
     * @brief Creates a new text entity
     * @param text text to display
     * @param fontSize text font size
     * @return smart pointer to the newly created text entity
     */
    virtual std::shared_ptr<controllers::TextController> loadText(std::basic_string<char> text, unsigned int fontSize) = 0;
};


#endif //DOODLEJUMP_ENTITYFACTORY_H
