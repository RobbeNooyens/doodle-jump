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

#ifndef DOODLEJUMP_SETTINGS_H
#define DOODLEJUMP_SETTINGS_H

#include <string>
#include <map>
#include "enums/BonusType.h"
#include "enums/PlatformType.h"

namespace settings {
    // Window
    // ==================================================
    const std::string applicationName = "DoodleJump";
    const unsigned int screenWidth = 400;
    const unsigned int screenHeight = 600;
    const unsigned int FPS = 60;

    // Resources
    // ==================================================
    const std::string resourceFile = "../resources/textures/config.json";
    const std::string resourceFolder = "../resources/textures/";
    const std::string font = "../resources/fonts/DoodleJump.ttf";
    const std::string highscoreFile = "../resources/files/highscore.txt";
    const unsigned int platformSize = 60;
    const unsigned int playerSize = 60;
    const unsigned int bonusSize = 20;


    // World generation
    // ==================================================
    // Bonuses
    const double bonusSpawnRate = 0.05;
    const std::map<BonusType, double> bonusRarityMap{
            {SPRING, 3},
            {JETPACK, 0.1}
    };
    const std::map<BonusType, double> spawnHeight{
            {SPRING, 100},
            {JETPACK, 1000}
    };
    // Platforms
    const double minPlatformDifference = 30;
    const double maxPlatformDifference = 120;
    const std::map<PlatformType, std::pair<double, double>> platformRarityMap = {
            {STATIC, {0, 5}},
            {HORIZONTAL, {(1/20000.0), 1}},
            {TEMPORARY, {(1/5000.0), -3}},
            {VERTICAL, {1/10000.0, -2}}
    };

    // Player movement
    // ==================================================
    const double acceleration = 15;
    const double jumpAmplifier = 1.2;
    const double maxHeight = screenHeight/(2.0);
    const double maxSpeed = 15;

}

#endif //DOODLEJUMP_SETTINGS_H
