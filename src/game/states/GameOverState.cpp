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

#include "GameOverState.h"
#include "../../wrappers/sfml/SFWrapperFactory.h"
#include "../../utils/TextureLoader.h"
#include "../../Settings.h"
#include "../../wrappers/SpriteWrapper.h"
#include "../../wrappers/WindowWrapper.h"
#include "../../wrappers/TextureWrapper.h"
#include "../../wrappers/TextWrapper.h"
#include "../../factories/EntityFactory.h"
#include "../../score/ScoreManager.h"
#include "../../controllers/TextController.h"

void states::GameOverState::update(double elapsed) {}

void states::GameOverState::draw(std::shared_ptr<wrappers::WindowWrapper> window) {
    window->draw(gameover);
    highScore->draw(window);
    score->draw(window);
}

states::GameOverState::GameOverState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::GAME_OVER, factory) {
    wrappers::sfml::SFWrapperFactory wrapperFactory{};
    gameover = wrapperFactory.createSprite();
    auto texture = TextureLoader::getInstance().getTexture("screen", "gameover");
    gameover->setTexture(texture);
    double scaleX = settings::screenWidth/texture->getWidth();
    double scaleY = settings::screenHeight/texture->getHeight();
    gameover->setScale((float)scaleX, (float)scaleY);
    score = factory->loadText(std::to_string((int) ScoreManager::getInstance().getScore()), settings::screenWidth/15);
    score->setPosition(settings::screenWidth*(0.54), settings::screenHeight*0.40);
    highScore = factory->loadText(std::to_string((int) ScoreManager::getInstance().getHighScore()), settings::screenWidth/15);
    highScore->setPosition(settings::screenWidth*0.70, settings::screenHeight*0.47);
}

states::GameOverState::~GameOverState() {
    gameover.reset();
    score.reset();
    highScore.reset();
}
