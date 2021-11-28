cmake_minimum_required(VERSION 3.10.2)
project(DoodleJump)

set(CMAKE_CXX_STANDARD 17)

file(GLOB sourcefiles
        "src/*.h"
        "src/*.cpp"
        "src/**/*.h"
        "src/**/*.cpp"
        )

add_executable(DoodleJump ${sourcefiles} src/views/Bonus.cpp src/views/Bonus.h src/models/Entity.h src/controllers/Bonus.cpp src/controllers/Bonus.h src/controllers/Platform.cpp src/controllers/Platform.h src/controllers/PlayerController.cpp src/controllers/PlayerController.h src/controllers/Tile.cpp src/controllers/Tile.h src/factories/AbstractFactory.h src/factories/ConcreteFactory.cpp src/factories/ConcreteFactory.h src/events/Event.h src/events/EventHandler.h src/events/KeyPressedEvent.cpp src/events/KeyPressedEvent.h src/controllers/EntityController.h src/views/EntityView.h src/views/EntityView.cpp)

# Find SFML
#set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)