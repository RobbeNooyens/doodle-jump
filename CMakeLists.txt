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


add_executable(DoodleJump ${sourcefiles} src/utils/Random.cpp src/enums/GameState.h src/exceptions/Exception.cpp src/exceptions/Exception.h src/exceptions/TextureNotFoundException.cpp src/exceptions/TextureNotFoundException.h src/exceptions/MissingResourceException.cpp src/exceptions/MissingResourceException.h src/game/GameState.h src/gui/WindowWrapper.h src/gui/SpriteWrapper.h src/gui/sfml/SFWindow.cpp src/gui/sfml/SFWindow.h src/gui/sfml/SFSprite.cpp src/gui/sfml/SFSprite.h src/gui/TextureWrapper.h src/gui/sfml/SFTexture.cpp src/gui/sfml/SFTexture.h src/game/GameErrorState.cpp src/game/GameErrorState.h src/game/GameMenuState.cpp src/game/GameMenuState.h src/game/GameRunningState.cpp src/game/GameRunningState.h src/gui/WrapperFactory.h src/gui/sfml/SFWrapperFactory.cpp src/gui/sfml/SFWrapperFactory.h src/gui/TextWrapper.h src/gui/sfml/SFText.cpp src/gui/sfml/SFText.h)

# Find SFML
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)