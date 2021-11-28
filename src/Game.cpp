//
// Created by robbe on 20/11/2021.
//

#include <iostream>
#include "Game.h"
#include "utils/Stopwatch.h"

#define MAX_CYCLES_PER_SECOND 30
#define MIN_TIME_PER_CYCLE (1000000000.0 / MAX_CYCLES_PER_SECOND)

Game::Game()
        : window(sf::VideoMode(640, 480), "Doodle Jump", sf::Style::Close),
          player(),
          texture(),
          circle(sf::CircleShape(100.f)) {
    if (!texture.loadFromFile("../resources/textures/ninja_doodler.png")) {
        throw std::runtime_error("texture not found");
    }
    player.setTexture(texture);
    circle.setFillColor(sf::Color::Green);
}

void Game::run() {
    Stopwatch clock = Stopwatch::getInstance();
    clock.start();
    clock.reset();
    sf::Event event;
    // Game loop
    while (window.isOpen()) {
        double elapsedSeconds = clock.elapsedSeconds();
        double elapsedMilliseconds = elapsedSeconds / 1000;
        double elapsedPicoseconds = elapsedSeconds / 1000000000;
        if (clock.elapsed() < MIN_TIME_PER_CYCLE)
            continue;

        while (window.pollEvent(event)) {
            if(event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed)
                return;
        }

        clock.reset();

        window.clear();
        window.draw(player);
        window.display();
    }

}