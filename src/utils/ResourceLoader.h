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

class BoundingBox;

struct Resource {
    Resource(double w, double h, std::shared_ptr<BoundingBox> bbox, const sf::Texture& texture)
        : width(w), height(h), boundingBox(std::move(bbox)), texture(texture) {}
    double width = 1;
    double height = 1;
    std::shared_ptr<BoundingBox> boundingBox;
    sf::Texture texture;
};

class ResourceLoader {
public:
    static ResourceLoader& getInstance();
    std::shared_ptr<Resource> getResource(std::string& entity_id, std::string& texture_id);
    void load(std::string& jsonFile);

    ResourceLoader(ResourceLoader()) = delete;
    void operator=(ResourceLoader const&) = delete;
private:
    ResourceLoader();
    std::map<std::string, std::map<std::string, std::shared_ptr<Resource>>> resources;


};


#endif //DOODLEJUMP_RESOURCELOADER_H
