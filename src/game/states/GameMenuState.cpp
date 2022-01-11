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

#include "GameMenuState.h"

#include "../../wrappers/SpriteWrapper.h"
#include "../../wrappers/WindowWrapper.h"
#include "../../wrappers/TextureWrapper.h"
#include "../../factories/EntityFactory.h"
#include "../../wrappers/sfml/SFWrapperFactory.h"
#include "../../utils/TextureLoader.h"
#include "../../Settings.h"

void states::GameMenuState::update(double elapsed) {}

void states::GameMenuState::draw(std::shared_ptr<wrappers::WindowWrapper> window) {
    window->draw(menu);
}

states::GameMenuState::GameMenuState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::MENU, factory) {
    wrappers::sfml::SFWrapperFactory wrapperFactory{};
    menu = wrapperFactory.createSprite();
    auto texture = TextureLoader::getInstance().getTexture("screen", "menu");
    menu->setTexture(texture);
    double scaleX = settings::screenWidth/texture->getWidth();
    double scaleY = settings::screenHeight/texture->getHeight();
    menu->setScale((float)scaleX, (float)scaleY);
}

states::GameMenuState::~GameMenuState() {
    menu.reset();
}
