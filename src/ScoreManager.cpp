//
// Created by robnoo on 4/12/21.
//

#include <fstream>
#include <iostream>
#include "ScoreManager.h"

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
    std::ifstream myfile ("../resources/files/highscore.txt");
    if (myfile.is_open()) {
        getline(myfile, line);
        myfile.close();
    } else {
        // TODO: error
        std::cout << "Unable to open file";
    }
    highScore = std::stod(line);
}

void ScoreManager::writeHighScore() const {
    // TODO: error
    std::ofstream myfile;
    myfile.open ("../resources/files/highscore.txt");
    myfile << highScore;
    myfile.close();
};
