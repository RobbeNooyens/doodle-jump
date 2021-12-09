//
// Created by robnoo on 4/12/21.
//

#ifndef DOODLEJUMP_SCOREMANAGER_H
#define DOODLEJUMP_SCOREMANAGER_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "events/EventHandler.h"

class ScoreManager {
public:
    static ScoreManager& getInstance();
    int getScore() const;
    void setScore(int score);
    sf::Text& getText();

private:
    ScoreManager();
    int score = 0;
    sf::Text scoreText;
    sf::Font font;

};


#endif //DOODLEJUMP_SCOREMANAGER_H
