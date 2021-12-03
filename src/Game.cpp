//
// Created by robbe on 20/11/2021.
//

#include <iostream>
#include "Game.h"
#include "utils/Stopwatch.h"
#include "controllers/EntityController.h"
#include "controllers/PlayerController.h"
#include "events/Event.h"
#include "events/KeyPressedEvent.h"
#include "events/EventManager.h"
#include "utils/ResourceLoader.h"
#include "factories/AbstractFactory.h"
#include "factories/ConcreteFactory.h"
#include "World.h"

#define MAX_CYCLES_PER_SECOND 30
#define MIN_TIME_PER_CYCLE (1000000000.0 / MAX_CYCLES_PER_SECOND)

Game::Game(): window(sf::VideoMode(400, 600), "Doodle Jump", sf::Style::Close) {}

void Game::run() {
    Stopwatch::getInstance().start();
    Stopwatch::getInstance().reset();
    sf::Event event;

    std::string jsonFile = "config.json";
    ResourceLoader::getInstance().load(jsonFile);

    World::getInstance().clear();
    World::getInstance().setup();

    // Game loop
    while (window.isOpen()) {
        if (Stopwatch::getInstance().elapsedSinceLastCycle() < MIN_TIME_PER_CYCLE)
            continue;

        while (window.pollEvent(event)) {
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Left) {
                    std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(KeyAction::LEFT);
                    EventManager::getInstance().invoke(ev);
                } else if(event.key.code == sf::Keyboard::Right) {
                    std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(KeyAction::RIGHT);
                    EventManager::getInstance().invoke(ev);
                }
            }
            if(event.type == sf::Event::Closed)
                return;
        }

        Stopwatch::getInstance().startCycle();

        // Update controllers
//        for(auto& controller: controllers) {
//            controller->update(clock.elapsedSinceLastCycle()/1000);
//        }
        World::getInstance().update(Stopwatch::getInstance().elapsedSinceLastCycle()/100);

        // Update camera

        window.clear();
        World::getInstance().redraw(window);
//        window.draw(world.getPlayer()->getSprite());
//        for(auto& entity: world.getPlatforms()) {
//            window.draw(entity->getSprite());
//        }
        window.display();
    }

}