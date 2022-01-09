//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFWINDOW_H
#define DOODLEJUMP_SFWINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "../WindowWrapper.h"

namespace wrappers::sfml {

    class SFWindow : public WindowWrapper {
    public:
        // Construtor
        SFWindow(const std::string &applicationName, unsigned int width, unsigned int height);

        // Forwarding calls
        bool isOpen() override;

        void clear() override;

        void display() override;

        bool pollEvent(std::shared_ptr<EventWrapper> &event) override;

        void draw(const std::shared_ptr<SpriteWrapper> &sprite) override;

        void draw(const std::shared_ptr<TextWrapper> &text) override;

    private:
        sf::RenderWindow window;

    };

}


#endif //DOODLEJUMP_SFWINDOW_H
