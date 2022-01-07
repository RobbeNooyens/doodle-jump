//
// Created by robnoo on 6/01/22.
//

#include "GameMenuState.h"

#include "../../wrappers/SpriteWrapper.h"
#include "../../wrappers/WindowWrapper.h"
#include "../../wrappers/TextureWrapper.h"
#include "../../factories/EntityFactory.h"
#include "../../wrappers/sfml/SFWrapperFactory.h"

void GameMenuState::update(double elapsed) {

}

void GameMenuState::draw(std::shared_ptr<WindowWrapper> window) {
    window->draw(menu);
}

GameMenuState::GameMenuState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::MENU, factory) {
    SFWrapperFactory wrapperFactory{};
    menu = wrapperFactory.createSprite();
    auto texture = TextureLoader::getInstance().getTexture("menu", "default");
    menu->setTexture(texture);
    double scaleX = settings::screenWidth/texture->getWidth();
    double scaleY = settings::screenHeight/texture->getHeight();
    menu->setScale(scaleX, scaleY);
}
