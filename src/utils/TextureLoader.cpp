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
#include "../exceptions/FileNotFoundException.h"
#include "../exceptions/ParseException.h"
#include "../exceptions/UndefinedException.h"
#include "../exceptions/TextureNotFoundException.h"

using json = nlohmann::json;

TextureLoader &TextureLoader::getInstance() {
    static TextureLoader INSTANCE;
    return INSTANCE;
}

void TextureLoader::load(const std::shared_ptr<wrappers::WrapperFactory> &factory) {
    std::string spritesConfig = settings::resourceFile;
    std::ifstream input(spritesConfig);

    if(!input.good()) {
        throw exceptions::FileNotFoundException(spritesConfig);
    }

    std::string t;

    json j;
    try {
        input >> j;
    } catch(nlohmann::json::exception & e) {
        throw exceptions::ParseException(spritesConfig, e.what());
    } catch(std::exception& e) {
        throw exceptions::UndefinedException(e.what());
    }

    try {
        for (const auto &entity: j.at("sprites")) {
            std::string entity_id = entity.at("id");
            auto textures_map = std::map<std::string, std::shared_ptr<wrappers::TextureWrapper>>();
            for (const auto &texture: entity.at("textures")) {
                std::string texture_id = texture.at("id");
                std::string source = texture.at("source");
                auto boundingBox = texture.at("bounding_box");
                double centerX = boundingBox.at("centerX");
                double centerY = boundingBox.at("centerY");
                double up = boundingBox.at("up");
                double down = boundingBox.at("down");
                double left = boundingBox.at("left");
                double right = boundingBox.at("right");
                double width = texture.at("width");
                double height = texture.at("height");
                auto bbox = std::make_shared<BoundingBox>(left, up, right, down);
                std::pair<double, double> center = {centerX, centerY};
                bbox->setCenter(center);
                textures_map.insert(
                        {texture_id, factory->createTexture(settings::resourceFolder + source, width, height, bbox)});
            }
            resources.insert({entity_id, textures_map});
        }
    } catch(nlohmann::detail::out_of_range& e) {
        throw exceptions::ParseException(spritesConfig, e.what());
    }

}

const std::shared_ptr<wrappers::TextureWrapper> & TextureLoader::getTexture(const std::string &entity_id, const std::string &texture_id) {
    try {
        return resources.at(entity_id).at(texture_id);
    } catch (std::out_of_range& e) {
        throw exceptions::TextureNotFoundException(entity_id, texture_id);
    }
}

TextureLoader::TextureLoader() = default;
