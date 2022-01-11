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

#ifndef DOODLEJUMP_SFWRAPPERFACTORY_H
#define DOODLEJUMP_SFWRAPPERFACTORY_H

#include "../WrapperFactory.h"

namespace wrappers::sfml {

    /**
     * @brief SFML wrapper for the WrapperFactory
     */
    class SFWrapperFactory : public WrapperFactory {
    public:
        /**
         * @brief Creates a smart pointer to a new sprite object
         * @return smart pointer to a new sprite wrapper
         */
        std::shared_ptr<wrappers::SpriteWrapper> createSprite() override;

        /**
         * @brief Creates a smart pointer to a new window object
         * @param applicationName name of the window
         * @param width window width
         * @param height window height
         * @return smart pointer to window wrapper
         */
        std::shared_ptr<WindowWrapper>
        createWindow(const std::string &applicationName, unsigned int width, unsigned int height) override;

        /**
         * @brief Creates a smart pointer to a new text object
         * @param content text to display
         * @param size font size
         * @return smart pointer to text object
         */
        std::shared_ptr<TextWrapper> createText(std::string &content, unsigned int size) override;

        /**
         * @brief Creates a smart pointer to a new texture object
         * @param file file name
         * @param width texture width
         * @param height texture height
         * @param bbox bounding box
         * @return smart pointer to a new texture
         */
        std::shared_ptr<TextureWrapper>
        createTexture(const std::string &file, double width, double height,
                      std::shared_ptr<BoundingBox> &bbox) override;

        /**
         * @brief Creates a smart pointer to a new event object
         * @return smart pointer to a new event object
         */
        std::shared_ptr<EventWrapper> createEvent() override;

    };

}

#endif //DOODLEJUMP_SFWRAPPERFACTORY_H
