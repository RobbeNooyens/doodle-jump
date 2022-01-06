//
// Created by robbe on 20/11/2021.
//

#include <iostream>
#include "Game.h"
#include "../utils/Stopwatch.h"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "../events/EventManager.h"
#include "../utils/ResourceLoader.h"
#include "../World.h"
#include "../Settings.h"
#include "../gui/WindowWrapper.h"
#include "../gui/sfml/SFWindow.h"

Game::Game(): window(std::make_unique<SFWindow>(settings::applicationName, settings::screenWidth, settings::screenHeight)) {}

void Game::run() {
    Stopwatch::getInstance().reset();
    sf::Event event;

    ResourceLoader::getInstance().load(jsonFile);

    World::getInstance().clear();
    World::getInstance().setup();

    double minCycleTime = 1000000000.0 / settings::FPS;

    // Game loop
    while (window->isOpen()) {
        // Ensure max FPS
        // TODO: move to settings
        if (Stopwatch::getInstance().elapsed() < minCycleTime)
            continue;

        // Check events
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                return;
            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                World::getInstance().spacebarPressed();
        }

        double elapsedNS = Stopwatch::getInstance().elapsedNanoseconds();
        Stopwatch::getInstance().reset();

        // Check keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(KeyAction::MOVE_LEFT);
            EventManager::getInstance().invoke(ev);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(KeyAction::MOVE_RIGHT);
            EventManager::getInstance().invoke(ev);
        }

        World::getInstance().update(elapsedNS/1000000000);

        window.clear();
        World::getInstance().redraw(window);
        window.display();
    }

}