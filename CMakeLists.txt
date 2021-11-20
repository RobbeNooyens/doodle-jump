cmake_minimum_required(VERSION 3.10.2)
project(DoodleJump)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
    FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)


    add_executable(DoodleJump src/main.cpp)

    include_directories(headers C:/SFML/include/)

    TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

else()
    set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
    FIND_PACKAGE(SFML 2.4 COMPONENTS system window graphics)

    add_executable(DoodleJump src/main.cpp)

    TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

endif()

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)