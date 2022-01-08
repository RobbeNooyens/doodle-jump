//
// Created by robnoo on 8/01/22.
//

#include "TextController.h"
#include "../views/TextView.h"
#include "../wrappers/WindowWrapper.h"

void controllers::TextController::draw(std::shared_ptr<WindowWrapper> &window) {
    window->draw(view->getText());
}

void controllers::TextController::setPosition(double x, double y) {
    view->setPosition(x, y);
}

controllers::TextController::~TextController() {
    view.reset();
}

void controllers::TextController::setTextWrapper(std::shared_ptr<TextWrapper> &wrapper) {
    view->setTextWrapper(wrapper);
}

void controllers::TextController::update(const std::string &s) {
    view->setText(s);
}

controllers::TextController::TextController(): view(std::make_shared<TextView>()) {};
