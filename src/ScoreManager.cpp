//
// Created by robnoo on 4/12/21.
//

#include "ScoreManager.h"
#include "events/Event.h"
#include "events/ReachedNewHeightEvent.h"
#include "Settings.h"

int ScoreManager::getScore() const {
    return score;
}

sf::Text& ScoreManager::getText() {
    return scoreText;
}

ScoreManager::ScoreManager() {
    if (!font.loadFromFile("../resources/fonts/DoodleJump.ttf"))
    {
        // TODO: error...
    }
    scoreText.setFont(font);
    scoreText.move(20, 10);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setString("0");
}

void ScoreManager::setScore(int s) {
    this->score = s;
    scoreText.setString(std::to_string(score));
}

ScoreManager &ScoreManager::getInstance() {
    static ScoreManager INSTANCE;
    return INSTANCE;
}

void ScoreManager::addScore(int s) {
    this->score += s;
};
