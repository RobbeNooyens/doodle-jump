/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "SFWindow.h"
#include "SFEvent.h"
#include "SFSprite.h"
#include "SFText.h"

wrappers::sfml::SFWindow::SFWindow(const std::string& applicationName, const unsigned int width, const unsigned int height):
window(sf::VideoMode(width, height), applicationName, sf::Style::Close) {}

bool wrappers::sfml::SFWindow::isOpen() {
    return window.isOpen();
}

void wrappers::sfml::SFWindow::clear() {
    window.clear();
}

void wrappers::sfml::SFWindow::display() {
    window.display();
}

bool wrappers::sfml::SFWindow::pollEvent(std::shared_ptr<EventWrapper> &event) {
    return window.pollEvent(std::static_pointer_cast<SFEvent>(event)->getEvent());
}

void wrappers::sfml::SFWindow::draw(const std::shared_ptr<SpriteWrapper> &sprite) {
    window.draw(std::static_pointer_cast<SFSprite>(sprite)->getSprite());
}

void wrappers::sfml::SFWindow::draw(const std::shared_ptr<TextWrapper> &text) {
    window.draw(std::static_pointer_cast<SFText>(text)->getText());
}
