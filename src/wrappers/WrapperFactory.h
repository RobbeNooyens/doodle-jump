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

#ifndef DOODLEJUMP_WRAPPERFACTORY_H
#define DOODLEJUMP_WRAPPERFACTORY_H

#include <memory>
#include "EventWrapper.h"

namespace wrappers {
    class SpriteWrapper;
    class TextureWrapper;
    class WindowWrapper;
    class TextWrapper;
}

class BoundingBox;

namespace wrappers {

    /**
     * @brief Wrapper for a GUI object factory
     */
    class WrapperFactory {
    public:
        /**
         * @brief Creates a sprite
         * @return sprite wrapper
         */
        virtual std::shared_ptr<wrappers::SpriteWrapper> createSprite() = 0;

        /**
         * @brief Creates a texture
         * @param file file that contains the textures
         * @param width texture width in pixels
         * @param height texture height in pixels
         * @param bbox texture bounding box in percentage
         * @return smart pointer to the loaded texture
         */
        virtual std::shared_ptr<wrappers::TextureWrapper>
        createTexture(const std::string &file, double width, double height, std::shared_ptr<BoundingBox> &bbox) = 0;

        /**
         * @brief Creates a window
         * @param applicationName application name to show in the window title bar
         * @param width window width
         * @param height window height
         * @return smart pointer to a window wrapper
         */
        virtual std::shared_ptr<wrappers::WindowWrapper>
        createWindow(const std::string &applicationName, unsigned int width, unsigned int height) = 0;

        /**
         * @brief Creates a text wrapper
         * @param content string to display
         * @param size font size
         * @return smart pointer to a text wrapper
         */
        virtual std::shared_ptr<wrappers::TextWrapper> createText(std::string &content, unsigned int size) = 0;

        /**
         * @brief Creates an event wrapper
         * @return smart pointer to an event wrapper
         */
        virtual std::shared_ptr<wrappers::EventWrapper> createEvent() = 0;
    };

}

#endif //DOODLEJUMP_WRAPPERFACTORY_H
