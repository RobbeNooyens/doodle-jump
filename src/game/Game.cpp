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
#include "../gui/EventWrapper.h"
#include "../gui/sfml/SFWrapperFactory.h"

Game::Game():
    wrapperFactory(std::make_shared<SFWrapperFactory>()),
    window(wrapperFactory->createWindow(settings::applicationName, settings::screenWidth, settings::screenHeight)),
    event(wrapperFactory->createEvent())
    {}

void Game::run() {
    Stopwatch::getInstance().reset();

    World::getInstance().clear();
    World::getInstance().setup();

    const double minCycleTime = 1000000000.0 / settings::FPS;

    // Game loop
    while (window->isOpen()) {
        // Ensure max FPS
        if (Stopwatch::getInstance().elapsed<double>() < minCycleTime)
            continue;

        checkEvents();

        auto elapsedNS = Stopwatch::getInstance().elapsedNanoseconds<double>();
        Stopwatch::getInstance().reset();

        checkKeyboardInput();

        World::getInstance().update(elapsedNS/1000000000);

        window->clear();
        World::getInstance().redraw(window);
        window->display();
    }

}

void Game::checkEvents() {
    while (window->pollEvent(event)) {
        if(event->getType() == WindowEventType::WINDOW_CLOSED)
            return;
        if(event->getType() == WindowEventType::KEY_RELEASED && event->getKey() == Keyboard::SPACEBAR)
            World::getInstance().spacebarPressed();
    }
}

void Game::checkKeyboardInput() {
    if (event->isKeyPressed(Keyboard::ARROW_LEFT) || event->isKeyPressed(Keyboard::A)) {
        std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(KeyAction::MOVE_LEFT);
        EventManager::getInstance().invoke(ev);
    } else if (event->isKeyPressed(Keyboard::ARROW_RIGHT) || event->isKeyPressed(Keyboard::D)) {
        std::shared_ptr<Event> ev = std::make_shared<KeyPressedEvent>(KeyAction::MOVE_RIGHT);
        EventManager::getInstance().invoke(ev);
    }
}
