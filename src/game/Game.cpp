//
// Created by robbe on 20/11/2021.
//

#include "Game.h"
#include "../utils/Stopwatch.h"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "../events/EventManager.h"
#include "../utils/TextureLoader.h"
#include "../world/World.h"
#include "../wrappers/WindowWrapper.h"
#include "../wrappers/EventWrapper.h"
#include "../wrappers/sfml/SFWrapperFactory.h"
#include "../factories/ConcreteEntityFactory.h"

Game::Game() {
    wrapperFactory = std::make_shared<SFWrapperFactory>();
    entityFactory = std::make_shared<ConcreteEntityFactory>(wrapperFactory);
    stateControl = std::make_shared<GameStateControl>(entityFactory);
    window = wrapperFactory->createWindow(settings::applicationName, settings::screenWidth, settings::screenHeight);
    event = wrapperFactory->createEvent();
    TextureLoader::getInstance().load(wrapperFactory);
    EventManager::getInstance().registerHandler(stateControl);
}

void Game::run() {
    Stopwatch::getInstance().reset();

    // Calculate min cycle time for a given FPS (ns)
    const double minCycleTime = 1000000000.0 / settings::FPS;

    // Game loop
    while (window->isOpen() && running) {
        // Ensure max FPS
        if (Stopwatch::getInstance().elapsed<double>() < minCycleTime)
            continue;

        auto elapsedNS = Stopwatch::getInstance().elapsedNanoseconds<double>();
        Stopwatch::getInstance().reset();

        checkEvents();
        checkKeyboardInput();

        stateControl->update(elapsedNS/1000000000);

        window->clear();
        stateControl->draw(window);
        window->display();
    }

}

void Game::checkEvents() {
    while (window->pollEvent(event)) {
        if(event->getType() == WindowEventType::WINDOW_CLOSED)
            running = false;
        else if(event->getType() == WindowEventType::KEY_RELEASED && event->getKey() == Keyboard::SPACEBAR)
            EventManager::getInstance().invoke(std::make_shared<KeyPressedEvent>(Keyboard::SPACEBAR));
    }
}

void Game::checkKeyboardInput() {
    for(auto key: {ARROW_LEFT, A, ARROW_RIGHT, D}) {
        if(event->isKeyPressed(key)) {
            EventManager::getInstance().invoke(std::make_shared<KeyPressedEvent>(key));
            break;
        }
    }
}
