//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFTEXT_H
#define DOODLEJUMP_SFTEXT_H


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../TextWrapper.h"

class SFText: public TextWrapper {
public:
    SFText(const std::string& content, unsigned int size);

    void setPosition(float x, float y) override;

    sf::Text& getText();

    void setText(const std::string &text) override;

private:
    static sf::Font font;
    static bool fontInitialized;
    sf::Text text;

};


#endif //DOODLEJUMP_SFTEXT_H