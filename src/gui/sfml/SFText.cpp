//
// Created by robnoo on 6/01/22.
//

#include "SFText.h"
#include "../../Settings.h"

bool SFText::fontInitialized = false;

SFText::SFText(const std::string& content, unsigned int size) {
    if(!fontInitialized) {
        if (!font.loadFromFile(settings::font)) {
            // TODO: error...
        }
        fontInitialized = true;
    }

    text.setString(content);
    text.setCharacterSize(size);
    text.setFont(font);
    text.move(0, 0);
    text.setFillColor(sf::Color::Black);
}

void SFText::moveTo(float x, float y) {
    text.move(x, y);
}
