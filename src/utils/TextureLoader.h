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

class TextureLoader {
public:
    const std::shared_ptr<wrappers::TextureWrapper> & getTexture(const std::string &entity_id, const std::string &texture_id);

    void load(const std::shared_ptr<wrappers::WrapperFactory> &factory);

    // Singleton specific
    static TextureLoader& getInstance();
    TextureLoader(TextureLoader()) = delete;
    void operator=(TextureLoader const&) = delete;

private:
    TextureLoader();
    std::map<std::string, std::map<std::string, std::shared_ptr<wrappers::TextureWrapper>>> resources;


};


#endif //DOODLEJUMP_TEXTURELOADER_H
