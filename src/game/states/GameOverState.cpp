//
// Created by robnoo on 6/01/22.
//

#include "GameOverState.h"
#include "../../wrappers/sfml/SFWrapperFactory.h"
#include "../../utils/TextureLoader.h"
#include "../../Settings.h"
#include "../../wrappers/SpriteWrapper.h"
#include "../../wrappers/WindowWrapper.h"
#include "../../wrappers/TextureWrapper.h"
#include "../../factories/EntityFactory.h"

void GameOverState::update(double elapsed) {

}

void GameOverState::draw(std::shared_ptr<WindowWrapper> window) {
    window->draw(gameover);
}

GameOverState::GameOverState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::GAME_OVER, factory) {
    SFWrapperFactory wrapperFactory{};
    gameover = wrapperFactory.createSprite();
    auto texture = TextureLoader::getInstance().getTexture("screen", "gameover");
    gameover->setTexture(texture);
    double scaleX = settings::screenWidth/texture->getWidth();
    double scaleY = settings::screenHeight/texture->getHeight();
    gameover->setScale((float)scaleX, (float)scaleY);
}

GameOverState::~GameOverState() {
    gameover.reset();
}
