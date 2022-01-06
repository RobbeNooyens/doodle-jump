//
// Created by robbe on 20/11/2021.
//

#include <iostream>
#include "Game.h"
#include "../utils/Stopwatch.h"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "../events/EventManager.h"
#include "../utils/TextureLoader.h"
#include "../World.h"
#include "../Settings.h"
#include "../gui/WindowWrapper.h"
#include "../gui/sfml/SFWindow.h"
#include "../gui/EventWrapper.h"
#include "../gui/sfml/SFWrapperFactory.h"

Game::Game():
    wrapperFactory(std::make_shared<SFWrapperFactory>()),
    window(wrapperFactory->createWindow(settings::applicationName, settings::screenWidth, settings::screenHeight)),
    event(wrapperFactory->createEvent())
    {
        TextureLoader::getInstance().load(wrapperFactory);
        auto stateControlEventHandler = std::static_pointer_cast<EventHandler>(stateControl);
        EventManager::getInstance().registerHandler(stateControlEventHandler);
    }

void Game::run() {
    Stopwatch::getInstance().reset();

    World::getInstance().clear();
    World::getInstance().setup();

    const double minCycleTime = 1000000000.0 / settings::FPS;

    // Game loop
    while (window->isOpen() && running) {
        // Ensure max FPS
        if (Stopwatch::getInstance().elapsed<double>() < minCycleTime)
            continue;

        checkEvents();

        auto elapsedNS = Stopwatch::getInstance().elapsedNanoseconds<double>();
        Stopwatch::getInstance().reset();

        checkKeyboardInput();

        stateControl->getCurrentState()->update(elapsedNS/1000000000);

        window->clear();
        stateControl->getCurrentState()->redraw(window);
        window->display();
    }

}

void Game::checkEvents() {
    while (window->pollEvent(event)) {
        if(event->getType() == WindowEventType::WINDOW_CLOSED){
            running = false;
            return;
        } else if(event->getType() == WindowEventType::KEY_RELEASED && event->getKey() == Keyboard::SPACEBAR) {
            std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(Keyboard::SPACEBAR);
            EventManager::getInstance().invoke(ev);
        }
    }
}

void Game::checkKeyboardInput() {
    for(auto key: {ARROW_LEFT, A, ARROW_RIGHT, D}) {
        if(event->isKeyPressed(key)) {
            std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(key);
            EventManager::getInstance().invoke(ev);
            break;
        }
    }
}
