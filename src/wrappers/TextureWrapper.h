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

#ifndef DOODLEJUMP_TEXTUREWRAPPER_H
#define DOODLEJUMP_TEXTUREWRAPPER_H

#include <string>
#include <memory>

class BoundingBox;

namespace wrappers {

    /**
     * @brief Wrapper for a texture object
     */
    class TextureWrapper {
    public:
        /**
         * @return texture's bounding box
         */
        [[nodiscard]] virtual const std::shared_ptr<BoundingBox> &getBoundingBox() const = 0;

        /**
         * @return texture width
         */
        [[nodiscard]] virtual double getWidth() const = 0;

        /**
         * @return texture height
         */
        [[nodiscard]] virtual double getHeight() const = 0;

    };

}

#endif //DOODLEJUMP_TEXTUREWRAPPER_H
