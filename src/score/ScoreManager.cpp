//
// Created by robnoo on 4/12/21.
//

#include <fstream>
#include <iostream>
#include "ScoreManager.h"
#include "../exceptions/FileNotFoundException.h"
#include "../Settings.h"

double ScoreManager::getScore() const {
    return score;
}

ScoreManager::ScoreManager() {
    readHighScore();
}

void ScoreManager::setScore(double s) {
    this->score = s;
    this->score = std::max(score, 0.0);
    if(score > highScore)
        highScore = score;
}

ScoreManager &ScoreManager::getInstance() {
    static ScoreManager INSTANCE;
    return INSTANCE;
}

void ScoreManager::addScore(double s) {
    setScore(score + s);
}

void ScoreManager::readHighScore() {
    std::string line;
    std::ifstream highScoreFile (settings::highscoreFile);
    if(!highScoreFile.good() || !highScoreFile.is_open()) {
        throw exceptions::FileNotFoundException(settings::highscoreFile);
    }
    getline(highScoreFile, line);
    highScoreFile.close();
    highScore = std::stod(line);
}

void ScoreManager::writeHighScore() const {
    std::ofstream highScoreFile;
    highScoreFile.open (settings::highscoreFile);
    if(!highScoreFile.good()) {
        throw exceptions::FileNotFoundException(settings::highscoreFile);
    }
    highScoreFile << highScore;
    highScoreFile.close();
}

double ScoreManager::getHighScore() const {
    return highScore;
};
