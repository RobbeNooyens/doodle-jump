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

/**
 * @brief Singleton that manages the score and highscore
 */
class ScoreManager {
public:
    /**
     * @return current score
     */
    [[nodiscard]] double getScore() const;
    /**
     * @return all-time highscore
     */
    [[nodiscard]] double getHighScore() const;

    /**
     * @param score new score
     */
    void setScore(double score);
    /**
     * @brief Adds points to the current score
     * @param score amount to add
     */
    void addScore(double score);

    /**
     * @brief Reads the highscore from the highscore file
     */
    void readHighScore();
    /**
     * @brief Writes the highscore to the highscore file
     */
    void writeHighScore() const;

    // Singleton specific
    /**
     * @return Singleton instance of ScoreManager
     */
    static ScoreManager& getInstance();

    ScoreManager(ScoreManager()) = delete;
    void operator=(ScoreManager const&) = delete;

private:
    ScoreManager();

    double score = 0;
    double highScore = 0;

};


#endif //DOODLEJUMP_SCOREMANAGER_H
