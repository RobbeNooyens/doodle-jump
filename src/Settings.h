//
// Created by robnoo on 3/12/21.
//

#ifndef DOODLEJUMP_SETTINGS_H
#define DOODLEJUMP_SETTINGS_H

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
    const std::map<PlatformType, double> platformRarityMap = {
            {STATIC, 5},
            {HORIZONTAL, 1},
            {TEMPORARY, 0.5},
            {VERTICAL, 0.1},
    };

    // Player movement
    // ==================================================
    const double acceleration = 15;
    const double jumpAmplifier = 1.2;
    const double maxHeight = screenHeight/(2.0);
    const double maxSpeed = 15;

}

#endif //DOODLEJUMP_SETTINGS_H
