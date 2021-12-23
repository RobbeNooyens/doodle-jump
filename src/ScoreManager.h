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
    double getScore() const;
    void setScore(double score);
    void addScore(double score);
    sf::Text& getText();

    ScoreManager(ScoreManager()) = delete;
    void operator=(ScoreManager const&) = delete;

private:
    void updateDisplay();
    ScoreManager();
    double score = 0;
    sf::Text scoreText;
    sf::Font font;

};


#endif //DOODLEJUMP_SCOREMANAGER_H
