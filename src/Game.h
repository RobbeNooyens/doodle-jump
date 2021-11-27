//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H


#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    sf::Sprite player;
    sf::Texture texture;
    sf::CircleShape circle;

};


#endif //DOODLEJUMP_GAME_H
