//
// Created by robbe on 20/11/2021.
//

#include <iostream>
#include "Game.h"
#include "utils/Stopwatch.h"

Game::Game()
: window(sf::VideoMode(640, 480), "Input", sf::Style::Close),
player(),
texture(),
circle(sf::CircleShape(100.f))
{
    if(!texture.loadFromFile("../resources/textures/ninja_doodler.png")) {
        throw std::runtime_error("texture not found");
    }
    player.setTexture(texture);
    circle.setFillColor(sf::Color::Green);
}

void Game::run() {
    Stopwatch clock = Stopwatch::getInstance();
    clock.start();
    clock.reset();
    // Game loop
    while(window.isOpen()) {
        double elapsedSeconds = clock.elapsedSeconds();
        double elapsedMilliseconds = elapsedSeconds/1000;
        double elapsedPicoseconds = elapsedSeconds/1000000000;
//        if(elapsedMilliseconds < 10)
//            continue;

        clock.reset();

        window.clear();
        window.draw(player);
        window.display();
    }

}
