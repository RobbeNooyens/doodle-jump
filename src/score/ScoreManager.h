/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#ifndef DOODLEJUMP_SCOREMANAGER_H
#define DOODLEJUMP_SCOREMANAGER_H

class ScoreManager {
public:
    [[nodiscard]] double getScore() const;
    [[nodiscard]] double getHighScore() const;

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
