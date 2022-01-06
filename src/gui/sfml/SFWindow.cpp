//
// Created by robnoo on 6/01/22.
//

#include "SFWindow.h"
#include "SFEvent.h"

SFWindow::SFWindow(const std::string& applicationName, const unsigned int width, const unsigned int height):
window(sf::VideoMode(width, height), applicationName, sf::Style::Close) {}

bool SFWindow::isOpen() {
    return window.isOpen();
}

void SFWindow::clear() {
    window.clear();
}

void SFWindow::display() {
    window.display();
}

bool SFWindow::pollEvent(std::shared_ptr<EventWrapper> &event) {
    // TODO: exception
    return window.pollEvent(std::static_pointer_cast<SFEvent>(event)->getEvent());
}
