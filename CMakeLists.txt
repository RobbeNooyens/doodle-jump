cmake_minimum_required(VERSION 3.10.2)
project(DoodleJump)

set(CMAKE_CXX_STANDARD 17)

file(GLOB sourcefiles
        "src/*.h"
        "src/*.cpp"
        "src/**/*.h"
        "src/**/*.cpp"
        "src/**/**/*.h"
        "src/**/**/*.cpp"
        )

# Compile option needed to prevent Clion from skipping breakpoints
add_compile_options(-gdwarf-4)


add_executable(DoodleJump ${sourcefiles} src/wrappers/EventWrapper.h src/wrappers/sfml/SFEvent.cpp src/wrappers/sfml/SFEvent.h src/enums/WindowEventType.h src/enums/Keyboard.h src/game/GameStateController.cpp src/game/GameStateController.h src/game/states/GameOverState.cpp src/game/states/GameOverState.h src/events/EventHandler.cpp src/events/PlayerDiedEvent.cpp src/events/PlayerDiedEvent.h)

# Find SFML
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)