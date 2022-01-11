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

#ifndef DOODLEJUMP_CONCRETEENTITYFACTORY_H
#define DOODLEJUMP_CONCRETEENTITYFACTORY_H

#include "EntityFactory.h"

namespace wrappers {
    class WrapperFactory;
}

/**
 * @brief Concrete factory to create new entities
 */
class ConcreteEntityFactory: public EntityFactory {
public:
    /**
     * @brief Parameter constructor
     * @param wrapperFactory factory to use to create graphical objects
     */
    explicit ConcreteEntityFactory(std::shared_ptr<wrappers::WrapperFactory>& wrapperFactory);
    /**
     * @brief Creates a new platform entity
     * @param platformType type of platform to create
     * @return smart pointer to the newly created platform
     */
    std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) override;
    /**
     * @brief Creates a new player entity
     * @return smart pointer to the newly created player
     */
    std::shared_ptr<controllers::PlayerController> loadPlayer() override;
    /**
     * @brief Creates a new bonus entity
     * @param bonusType type of bonus to create
     * @return smart pointer to the newly created bonus
     */
    std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) override;
    /**
     * @brief Creates a new tile entity
     * @return smart pointer to the newly created tile
     */
    std::shared_ptr<controllers::TileController> loadTile() override;
    /**
     * @brief Creates a new text entity
     * @param text text to display
     * @param fontSize text font size
     * @return smart pointer to the newly created text entity
     */
    std::shared_ptr<controllers::TextController> loadText(std::basic_string<char> text, unsigned int size) override;

private:
    std::shared_ptr<wrappers::WrapperFactory> wrapperFactory{};

};


#endif //DOODLEJUMP_CONCRETEENTITYFACTORY_H
