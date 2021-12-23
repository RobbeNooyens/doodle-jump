//
// Created by robnoo on 4/12/21.
//

#include "ScoreManager.h"
#include "events/Event.h"
#include "events/ReachedNewHeightEvent.h"
#include "Settings.h"

double ScoreManager::getScore() const {
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
    updateDisplay();
}

void ScoreManager::setScore(double s) {
    this->score = s;
    this->score = std::max(score, 0.0);
    updateDisplay();
}

ScoreManager &ScoreManager::getInstance() {
    static ScoreManager INSTANCE;
    return INSTANCE;
}

void ScoreManager::addScore(double s) {
    this->score += s;
    this->score = std::max(score, 0.0);
    updateDisplay();
}

void ScoreManager::updateDisplay() {
    scoreText.setString(std::to_string((int)score));
};
