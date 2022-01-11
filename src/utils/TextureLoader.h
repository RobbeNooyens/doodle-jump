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

#ifndef DOODLEJUMP_TEXTURELOADER_H
#define DOODLEJUMP_TEXTURELOADER_H

#include <map>
#include <string>
#include <memory>

namespace wrappers {
    class WrapperFactory;
    class TextureWrapper;
}

/**
 * @brief Singleton that loads and stores textures
 */
class TextureLoader {
public:
    /**
     * @param entity_id id of entity of requested texture
     * @param texture_id texture id
     * @return smart pointer to texture if found
     * @throws exceptions::TextureNotFoundException if entityId or textureId not found
     */
    const std::shared_ptr<wrappers::TextureWrapper> & getTexture(const std::string &entity_id, const std::string &texture_id);

    /**
     * @brief Load textures created with given factory in memory
     * @param factory factory to create textures with
     */
    void load(const std::shared_ptr<wrappers::WrapperFactory> &factory);

    // Singleton specific
    /**
     * @return static singleton instance of TextureLoader
     */
    static TextureLoader& getInstance();

    TextureLoader(TextureLoader()) = delete;
    void operator=(TextureLoader const&) = delete;

private:
    TextureLoader();
    std::map<std::string, std::map<std::string, std::shared_ptr<wrappers::TextureWrapper>>> resources{};


};


#endif //DOODLEJUMP_TEXTURELOADER_H
