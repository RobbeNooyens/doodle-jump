//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMESTATE_H
#define DOODLEJUMP_GAMESTATE_H

#include <memory>
#include "../../enums/GameStateType.h"

class WindowWrapper;
class EntityFactory;

class GameState {
public:
    // Constructor
    explicit GameState(GameStateType type, std::shared_ptr<EntityFactory>& factory): gameStateType(type), factory(factory) {};
    virtual ~GameState() {factory.reset();}

    // Getters
    GameStateType getType() { return gameStateType; }

    // Actions
    virtual void update(double elapsed) = 0;
    virtual void draw(std::shared_ptr<WindowWrapper>) = 0;

protected:
    std::shared_ptr<EntityFactory> factory;

private:
    GameStateType gameStateType;
};

#endif //DOODLEJUMP_GAMESTATE_H
