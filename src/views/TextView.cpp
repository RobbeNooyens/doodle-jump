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

#include "TextView.h"

#include "../wrappers/TextWrapper.h"

const std::shared_ptr<wrappers::TextWrapper> &TextView::getText() {
    return text;
}

void TextView::setText(const std::string &t) {
    text->setText(t);
}

void TextView::setPosition(double x, double y) {
    text->setPosition((float) x, (float) y);
}

void TextView::setTextWrapper(std::shared_ptr<wrappers::TextWrapper> &wrapper) {
    text = wrapper;
}

TextView::~TextView() {
    text.reset();
}
