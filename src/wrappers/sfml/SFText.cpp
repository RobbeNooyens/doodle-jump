//
// Created by robnoo on 6/01/22.
//

#include "SFText.h"

#include <SFML/Graphics/Font.hpp>

#include "../../Settings.h"
#include "../../exceptions/FontLoadException.h"

bool SFText::fontInitialized = false;
sf::Font SFText::font;

SFText::SFText(const std::string& content, unsigned int size) {
    if(!fontInitialized) {
        std::string fontFile = settings::font;
        if (!font.loadFromFile(fontFile)) {
            throw exceptions::FontLoadException(fontFile);
        }
        fontInitialized = true;
    }

    text.setString(content);
    text.setCharacterSize(size);
    text.setFont(font);
    text.move(0, 0);
    text.setFillColor(sf::Color::Black);
}

void SFText::setPosition(float x, float y) {
    text.move(x, y);
}

sf::Text &SFText::getText() {
    return text;
}

void SFText::setText(const std::string &t) {
    text.setString(t);
}
