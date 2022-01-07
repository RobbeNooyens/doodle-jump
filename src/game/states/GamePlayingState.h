//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEPLAYINGSTATE_H
#define DOODLEJUMP_GAMEPLAYINGSTATE_H


#include "GameState.h"

class World;
class WorldGenerator;
class EntityFactory;

class GamePlayingState: public GameState {
public:
    explicit GamePlayingState(std::shared_ptr<EntityFactory>& factory);

    void update(double elapsed) override;
    void draw(std::shared_ptr<WindowWrapper> window) override;

private:
    std::shared_ptr<World> world;
    std::shared_ptr<WorldGenerator> worldGenerator;
};


#endif //DOODLEJUMP_GAMEPLAYINGSTATE_H
