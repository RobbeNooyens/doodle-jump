cmake_minimum_required(VERSION 3.10.2)
project(DoodleJump)
project(DoodleJumpLogic)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        # src directory
        src/main.cpp
        src/Settings.h
        # bouncing_box
        src/bounding_box/BoundingBox.cpp
        src/bounding_box/BoundingBox.h
        # controllers
        src/controllers/BonusController.cpp
        src/controllers/BonusController.h
        src/controllers/EntityController.cpp
        src/controllers/EntityController.h
        src/controllers/PlatformController.cpp
        src/controllers/PlatformController.h
        src/controllers/PlayerController.cpp
        src/controllers/PlayerController.h
        src/controllers/TextController.cpp
        src/controllers/TextController.h
        src/controllers/TileController.cpp
        src/controllers/TileController.h
        # enums
        src/enums/BonusType.h
        src/enums/Direction.h
        src/enums/GameEventType.h
        src/enums/GameStateType.h
        src/enums/Keyboard.h
        src/enums/PlatformType.h
        src/enums/WindowEventType.h
        # events
        src/events/Event.h
        src/events/EventHandler.cpp
        src/events/EventHandler.h
        src/events/EventManager.cpp
        src/events/EventManager.h
        src/events/HeightChangedEvent.cpp
        src/events/HeightChangedEvent.h
        src/events/KeyPressedEvent.cpp
        src/events/KeyPressedEvent.h
        src/events/PlayerBouncesOnPlatformEvent.cpp
        src/events/PlayerBouncesOnPlatformEvent.h
        src/events/PlayerDiedEvent.cpp
        src/events/PlayerDiedEvent.h
        src/events/PlayerUsesBonusEvent.cpp
        src/events/PlayerUsesBonusEvent.h
        # exceptions
        src/exceptions/Exception.h
        src/exceptions/FileNotFoundException.h
        src/exceptions/FontLoadException.h
        src/exceptions/ParseException.h
        src/exceptions/TextureLoadException.h
        src/exceptions/TextureNotFoundException.h
        src/exceptions/UndefinedException.h
        #factories
        src/factories/ConcreteEntityFactory.cpp
        src/factories/ConcreteEntityFactory.h
        src/factories/EntityFactory.h
        # game
        src/game/Game.cpp
        src/game/Game.h
        src/game/GameStateController.cpp
        src/game/GameStateController.h
        # models
        src/models/BonusModel.cpp
        src/models/BonusModel.h
        src/models/EntityModel.cpp
        src/models/EntityModel.h
        src/models/PlatformModel.cpp
        src/models/PlatformModel.h
        src/models/PlayerModel.cpp
        src/models/PlayerModel.h
        src/models/TileModel.cpp
        src/models/TileModel.h
        # score
        src/score/ScoreManager.cpp
        src/score/ScoreManager.h
        # utils
        src/utils/Random.cpp
        src/utils/Random.h
        src/utils/Stopwatch.cpp
        src/utils/Stopwatch.h
        src/utils/TextureLoader.cpp
        src/utils/TextureLoader.h
        # views
        src/views/BonusView.cpp
        src/views/BonusView.h
        src/views/EntityView.cpp
        src/views/EntityView.h
        src/views/PlatformView.cpp
        src/views/PlatformView.h
        src/views/PlayerView.cpp
        src/views/PlayerView.h
        src/views/TextView.cpp
        src/views/TextView.h
        src/views/TileView.cpp
        src/views/TileView.h
        # world
        src/world/Camera.cpp
        src/world/Camera.h
        src/world/World.cpp
        src/world/World.h
        src/world/WorldGenerator.cpp
        src/world/WorldGenerator.h
        # wrappers
        src/wrappers/EventWrapper.h
        src/wrappers/SpriteWrapper.h
        src/wrappers/TextureWrapper.h
        src/wrappers/TextWrapper.h
        src/wrappers/WindowWrapper.h
        src/wrappers/WrapperFactory.h
        # game states
        src/game/states/GameErrorState.cpp
        src/game/states/GameErrorState.h
        src/game/states/GameMenuState.cpp
        src/game/states/GameMenuState.h
        src/game/states/GameOverState.cpp
        src/game/states/GameOverState.h
        src/game/states/GamePlayingState.cpp
        src/game/states/GamePlayingState.h
        src/game/states/GameState.h
        )

set(SFML_WRAPPER_FILES
        src/wrappers/sfml/SFEvent.cpp
        src/wrappers/sfml/SFEvent.h
        src/wrappers/sfml/SFSprite.cpp
        src/wrappers/sfml/SFSprite.h
        src/wrappers/sfml/SFText.cpp
        src/wrappers/sfml/SFText.h
        src/wrappers/sfml/SFTexture.cpp
        src/wrappers/sfml/SFTexture.h
        src/wrappers/sfml/SFWindow.cpp
        src/wrappers/sfml/SFWindow.h
        src/wrappers/sfml/SFWrapperFactory.cpp
        src/wrappers/sfml/SFWrapperFactory.h
        )

# Compile option needed to prevent Clion from skipping breakpoints
add_compile_options(-gdwarf-4)


add_executable(DoodleJump ${SOURCE_FILES} ${SFML_WRAPPER_FILES})
add_executable(DoodleJumpLogic ${SOURCE_FILES} "src/wrappers/sfml/SFWrapperFactory.h" "src/wrappers/sfml/SFWrapperFactoryLogic.cpp")

# Find SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2.4 COMPONENTS graphics window system)

TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)
INSTALL(TARGETS DoodleJumpLogic DESTINATION ${PROJECT_SOURCE_DIR}/bin)