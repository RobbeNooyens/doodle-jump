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

# Compile option needed to prevent Clion from skipping breakpoints and to use multithreading
add_compile_options(-gdwarf-4 -O3 -pthread)


add_executable(DoodleJump ${sourcefiles} src/exceptions/FontLoadException.h src/exceptions/TextureLoadException.h)

# Find SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)