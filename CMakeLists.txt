cmake_minimum_required(VERSION 3.10.2)
project(DoodleJump)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
FIND_PACKAGE(SFML 2.5.1 COMPONENTS system window graphics)

add_executable(DoodleJump src/main.cpp
        src/logic/entities/Entity.h
        src/logic/entities/Doodler.h src/logic/entities/Doodler.cpp
        src/logic/entities/BoundingBox.h src/logic/entities/BoundingBox.cpp)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)