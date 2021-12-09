cmake_minimum_required(VERSION 3.10.2)
project(DoodleJump)

set(CMAKE_CXX_STANDARD 17)

file(GLOB sourcefiles
        "src/*.h"
        "src/*.cpp"
        "src/**/*.h"
        "src/**/*.cpp"
        )

# Compile option needed to prevent Clion from skipping breakpoints
add_compile_options(-gdwarf-4)


add_executable(DoodleJump ${sourcefiles} src/utils/ResourceLoader.cpp src/utils/ResourceLoader.h src/controllers/EntityController.cpp src/enums/Direction.h src/Settings.h src/enums/PlatformType.h src/WorldGenerator.cpp src/WorldGenerator.h src/ScoreManager.cpp src/ScoreManager.h)

# Find SFML
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)