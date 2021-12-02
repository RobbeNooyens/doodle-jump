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

struct BoundingBox {
    BoundingBox(double centerX, double centerY, double up, double down, double left, double right)
    : center({centerX, centerY}), left(left), right(right), up(up), down(down) {}
    std::pair<double, double> center;
    double left, right, up, down;
};

class ResourceLoader {
public:
    static ResourceLoader& getInstance();
    std::shared_ptr<BoundingBox>& getBoundingBox(std::string& entity_id, std::string& texture_id);
    sf::Texture& getTexture(std::string& entity_id, std::string& texture_id);
    void load(std::string& jsonFile);
private:
    ResourceLoader();

    std::map<std::string, std::map<std::string, std::pair<sf::Texture, std::shared_ptr<BoundingBox>>>> resources;


};


#endif //DOODLEJUMP_RESOURCELOADER_H
