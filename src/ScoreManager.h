//
// Created by robnoo on 4/12/21.
//

#ifndef DOODLEJUMP_SCOREMANAGER_H
#define DOODLEJUMP_SCOREMANAGER_H

#include "events/EventHandler.h"

class ScoreManager {
public:
    [[nodiscard]] double getScore() const;
    void setScore(double score);
    void addScore(double score);

    void readHighScore();
    void writeHighScore() const;

    // Singleton specific
    static ScoreManager& getInstance();
    ScoreManager(ScoreManager()) = delete;
    void operator=(ScoreManager const&) = delete;

private:
    ScoreManager();

    double score = 0;
    double highScore = 0;

};


#endif //DOODLEJUMP_SCOREMANAGER_H
