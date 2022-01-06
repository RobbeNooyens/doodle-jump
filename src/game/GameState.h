//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMESTATE_H
#define DOODLEJUMP_GAMESTATE_H

class GameState {
public:
    virtual void update(double elapsed) = 0;
    virtual void redraw(std::shared_ptr<>) = 0;
};

#endif //DOODLEJUMP_GAMESTATE_H
