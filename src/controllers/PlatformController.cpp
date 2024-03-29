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

#include "PlatformController.h"
#include "../events/Event.h"
#include "../events/HeightChangedEvent.h"
#include "../score/ScoreManager.h"
#include "../events/PlayerBouncesOnPlatformEvent.h"
#include "../models/PlatformModel.h"
#include "../views/PlatformView.h"
#include "../controllers/BonusController.h"
#include "../Settings.h"

controllers::PlatformController::PlatformController(PlatformType type): EntityController(), platformType(type) {
    view = std::make_shared<views::PlatformView>();
}

controllers::StaticPlatformController::StaticPlatformController(): PlatformController(STATIC) {
    model = std::make_shared<models::StaticPlatform>();
}

controllers::TemporaryPlatformController::TemporaryPlatformController(): PlatformController(TEMPORARY) {
    model = std::make_shared<models::TemporaryPlatform>();
}

controllers::HorizontalPlatformController::HorizontalPlatformController(): PlatformController(HORIZONTAL) {
    model = std::make_shared<models::HorizontalPlatform>();
}

controllers::VerticalPlatformController::VerticalPlatformController(): PlatformController(VERTICAL) {
    model = std::make_shared<models::VerticalPlatform>();
}

PlatformType controllers::PlatformController::getType() {
    return platformType;
}

void controllers::PlatformController::handle(std::shared_ptr<events::Event> &event) {
    if(event->getType() == HEIGHT_CHANGED) {
        auto heightEvent = std::static_pointer_cast<events::HeightChangedEvent>(event);
        this->changeY(heightEvent->getDifference());
    }

    if(event->getType() == PLAYER_BOUNCES_ON_PLATFORM) {
        auto bounceEvent = std::static_pointer_cast<events::PlayerBouncesOnPlatformEvent>(event);
        if(bounceEvent->getPlatformId() == getId()) {
            jumpCount++;
            if(jumpCount > 1) {
                // Subtract points if the player jumps on the same platform multiple times
                ScoreManager::getInstance().addScore(-jumpCount*50);
            } else {
                // Add extra points depending on the type of platform
                ScoreManager::getInstance().addScore(settings::platformBouncePoints.at(getType()));

            }
            if(getType() == TEMPORARY) {
                destroy();
            }
        }
    }
}

void controllers::PlatformController::setBonus(std::shared_ptr<BonusController> &bonusController) {
    this->bonus = bonusController;
}

void controllers::PlatformController::goesBeneathScreen() {
    if(!bonus.lock() && isBeneathScreen()) {
        destroy();
    }
}

bool controllers::PlatformController::isBeneathScreen() {
    return std::static_pointer_cast<models::PlatformModel>(model)->isBeneathScreen();
}
