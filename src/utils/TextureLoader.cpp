//
// Created by robnoo on 1/12/21.
//

#include <fstream>
#include "TextureLoader.h"
#include "../../libraries/json.hpp"
#include "../bounding_box/BoundingBox.h"
#include "../Settings.h"
#include "../wrappers/TextureWrapper.h"
#include "../wrappers/WrapperFactory.h"

using json = nlohmann::json;

TextureLoader &TextureLoader::getInstance() {
    static TextureLoader INSTANCE;
    return INSTANCE;
}

void TextureLoader::load(const std::shared_ptr<WrapperFactory> &factory) {
    std::ifstream input(settings::resourceFile);

    std::string t;
    json j;
    input >> j;

    // TODO error checking
    for(const auto& entity: j["sprites"]) {
        std::string entity_id = entity["id"];
        auto textures_map = std::map<std::string, std::shared_ptr<TextureWrapper>>();
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
            auto bbox = std::make_shared<BoundingBox>(left, up, right, down);
            std::pair<double, double> center = {centerX, centerY};
            bbox->setCenter(center);
            // TODO: error handling
            textures_map.insert({texture_id, factory->createTexture(settings::resourceFolder + source, width, height, bbox)});
        }
        resources.insert({entity_id, textures_map});
    }

}

const std::shared_ptr<TextureWrapper> & TextureLoader::getTexture(const std::string &entity_id, const std::string &texture_id) {
    return resources.at(entity_id).at(texture_id);
}

TextureLoader::TextureLoader() = default;
