//
// Created by robnoo on 1/12/21.
//

#include <fstream>
#include "ResourceLoader.h"
#include "../../libraries/json.hpp"

using json = nlohmann::json;

ResourceLoader &ResourceLoader::getInstance() {
    static ResourceLoader INSTANCE;
    return INSTANCE;
}

void ResourceLoader::load(std::string &jsonFile) {
    std::ifstream input("../resources/textures/" + jsonFile);

    std::string t;
    json j;
    input >> j;

    for(const auto& entity: j["entities"]) {
        std::string entity_id = entity["id"];
        auto textures_map = std::map<std::string, std::shared_ptr<Resource>>();
        for(const auto& texture: entity["textures"]) {
            // TODO: replace accessors with .at() for nullpointer instead of segfault
            std::string texture_id = texture["id"];
            std::string source = texture["source"];
            double centerX = texture["bounding_box"]["centerX"];
            double centerY = texture["bounding_box"]["centerY"];
            double up = texture["bounding_box"]["up"];
            double down = texture["bounding_box"]["down"];
            double left = texture["bounding_box"]["left"];
            double right = texture["bounding_box"]["right"];
            double width = texture["width"];
            double height = texture["height"];
            std::shared_ptr<BoundingBox> bbox = std::make_shared<BoundingBox>(centerX, centerY, up, down, left, right);
            sf::Texture textureObj;
            textureObj.loadFromFile("../resources/textures/" + source);
            textures_map.insert({texture_id, std::make_shared<Resource>(width, height, bbox, textureObj)});
        }
        resources.insert({entity_id, textures_map});
    }

}

std::shared_ptr<Resource> ResourceLoader::getResource(std::string& entity_id, std::string &texture_id) {
    return resources.at(entity_id).at(texture_id);
}

ResourceLoader::ResourceLoader() = default;
