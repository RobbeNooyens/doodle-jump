//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_RESOURCELOADER_H
#define DOODLEJUMP_RESOURCELOADER_H

#include <utility>
#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <memory>

class WrapperFactory;
class TextureWrapper;

class ResourceLoader {
public:
    const std::shared_ptr<TextureWrapper> & getResource(const std::string &entity_id, const std::string &texture_id);

    void load(const std::shared_ptr<WrapperFactory> &factory);

    // Singleton specific
    static ResourceLoader& getInstance();
    ResourceLoader(ResourceLoader()) = delete;
    void operator=(ResourceLoader const&) = delete;
private:
    ResourceLoader();

    std::map<std::string, std::map<std::string, std::shared_ptr<TextureWrapper>>> resources;


};


#endif //DOODLEJUMP_RESOURCELOADER_H
