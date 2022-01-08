//
// Created by robnoo on 8/01/22.
//

#include "TextView.h"

#include "../wrappers/TextWrapper.h"

const std::shared_ptr<TextWrapper> &TextView::getText() {
    return text;
}

void TextView::setText(const std::string &t) {
    text->setText(t);
}

void TextView::setPosition(double x, double y) {
    text->setPosition((float) x, (float) y);
}

void TextView::setTextWrapper(std::shared_ptr<TextWrapper> &wrapper) {
    text = wrapper;
}

TextView::~TextView() {
    text.reset();
}
